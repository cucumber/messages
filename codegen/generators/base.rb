# frozen_string_literal: true

require 'json'
require 'erb'
require 'set'

module Generator
  # Generator::Base
  # Automatic Code generation base class for generating cucumber messages
  class Base
    TEMPLATES_DIRECTORY = "#{File.dirname(__FILE__)}/../templates".freeze

    def initialize(paths, language_type_by_schema_type)
      @paths = paths
      @language_type_by_schema_type = language_type_by_schema_type
      @schemas = {}
      @enum_set = Set.new
      add_all_schemas
      @schemas = @schemas.sort
      @enums = @enum_set.to_a.sort_by { |a| a[:name] }
    end

    def generate(template_name)
      template_source = File.read("#{TEMPLATES_DIRECTORY}/#{template_name}")
      template = ERB.new(template_source, trim_mode: '-')
      $stdout.write(template.result(binding))
    end

    private

    def add_all_schemas
      @paths.each do |path|
        schema = JSON.parse(File.read(path))
        add_individual_schema(File.expand_path(path), schema)
      rescue JSON::ParserError => e
        e.message << "\npath: #{path}"
        raise e
      end
    end

    def add_individual_schema(key, schema)
      @schemas[key] = schema
      (schema['definitions'] || {}).each do |name, subschema|
        subkey = "#{key}/#{name}"
        add_individual_schema(subkey, subschema)
      end

      schema['properties'].each do |property_name, property|
        enum = property['enum']
        enum_name(class_name(key), property_name, enum) if enum
      end
    end

    def capitalize(string)
      string.sub(/./, &:upcase)
    end

    def class_name(ref)
      File.basename(ref, '.json')
    end

    def default_enum(enum_type_name, property)
      "#{enum_type_name}.#{enum_constant(property['enum'][0])}"
    end

    def default_value(parent_type_name, property_name, property)
      if property['items']
        '[]'
      elsif %w[string integer boolean].include?(property['type'])
        default_value_for_non_objects(parent_type_name, property_name, property)
      elsif property['$ref']
        "new #{type_for(parent_type_name, nil, property)}()"
      else
        raise "Cannot create default value for #{parent_type_name}##{property.to_json}"
      end
    end

    def default_value_for_non_objects(parent_type_name, property_name, property)
      case property['type']
      when 'string'
        if property['enum']
          enum_type_name = type_for(parent_type_name, property_name, property)
          default_enum(enum_type_name, property)
        else
          "''"
        end
      when 'integer'; then '0'
      when 'boolean'; then 'false'
      end
    end

    def enum_constant(value)
      value.gsub(/[.\/+]/, '_').upcase
    end

    def enum_name(parent_type_name, property_name, enum)
      enum_type_name = "#{parent_type_name}#{capitalize(property_name)}"
      @enum_set.add({ name: enum_type_name, values: enum })
      enum_type_name
    end

    def property_type_from_enum(enum)
      enum
    end

    def property_type_from_ref(ref)
      class_name(ref)
    end

    def property_type_from_type(parent_type_name, property_name, property, type:)
      return array_type_for(type_for(parent_type_name, nil, property['items'])) if type == 'array'

      unless @language_type_by_schema_type[type]
        raise "No type mapping for JSONSchema type #{type}. Schema:\n#{JSON.pretty_generate(property)}"
      end

      if property['enum']
        property_type_from_enum(enum_name(parent_type_name, property_name, property['enum']))
      else
        @language_type_by_schema_type[type]
      end
    end

    def type_for(parent_type_name, property_name, property)
      if property['$ref']
        property_type_from_ref(property['$ref'])
      elsif property['type']
        property_type_from_type(parent_type_name, property_name, property, type: property['type'])
      else
        # Inline schema (not supported)
        raise "Property #{property_name} did not define 'type' or '$ref'"
      end
    end

    # Adapted from rails -> https://github.com/rails/rails/blob/v6.1.3.2/activesupport/lib/active_support/inflector/methods.rb#L92
    def underscore(camel_cased_word)
      return camel_cased_word unless /[A-Z-]/.match?(camel_cased_word)

      camel_cased_word.gsub(/([A-Z\d]+)([A-Z][a-z])/, '\1_\2')
                      .gsub(/([a-z\d])([A-Z])/, '\1_\2')
                      .tr('-', '_')
                      .downcase
    end
  end
end
