# frozen_string_literal: true

require 'json'
require 'erb'
require 'set'

module Generator
  # Generator::Base
  # Automatic Code generation base class for generating cucumber messages
  class Base
    TEMPLATES_DIRECTORY = "#{File.dirname(__FILE__)}/../templates".freeze

    include TextHelpers

    def initialize(paths: Dir['../jsonschema/src/*.json'])
      @paths = paths
      @schemas = {}
      @enum_set = Set.new
      add_all_schemas
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
      @schemas = @schemas.sort
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
      when 'string'; then default_value_for_string(parent_type_name, property_name, property)
      when 'integer'; then '0'
      when 'boolean'; then 'false'
      end
    end

    def default_value_for_string(parent_type_name, property_name, property)
      if property['enum']
        enum_type_name = type_for(parent_type_name, property_name, property)
        default_enum(enum_type_name, property)
      else
        "''"
      end
    end

    def enum_constant(value)
      value.gsub(/[.\/+]/, '_').upcase
    end

    def enum_name(parent_type_name, property_name, enum)
      "#{parent_type_name}#{capitalize(property_name)}".tap { |name| @enum_set.add({ name: name, values: enum }) }
    end

    def property_type_from_enum(enum)
      enum
    end

    def property_type_from_ref(ref)
      class_name(ref)
    end

    def property_type_from_type(parent_type_name, property_name, property)
      type = property['type']
      return array_type_for(type_for(parent_type_name, nil, property['items'])) if type == 'array'
      return property_type_from_enum(enum_name(parent_type_name, property_name, property['enum'])) if property['enum']

      property = select_language_translations_for_data_types(type, property)
      unless property
        raise "No type mapping for JSONSchema type #{type}. Schema:\n#{JSON.pretty_generate(property)}"
      end
      property
    end

    def type_for(parent_type_name, property_name, property)
      if property['$ref']
        property_type_from_ref(property['$ref'])
      elsif property['type']
        property_type_from_type(parent_type_name, property_name, property)
      else
        # Inline schema (not supported)
        raise "Property #{property_name} did not define 'type' or '$ref'"
      end
    end
  end
end
