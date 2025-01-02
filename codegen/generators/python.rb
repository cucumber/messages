# frozen_string_literal: true

module Generator
  class Python < Base
    def format_enum_value(value)
      value.downcase.gsub(/[.\/+\s-]/, '_')
    end

    def get_sorted_properties(definition)
      required_fields = definition['required'] || []
      definition['properties'].sort_by do |name, *|
        [required_fields.include?(name) ? 0 : 1, name]
      end
    end

    def format_property(parent_type_name, property_name, property, required_fields)
      snake_name = property_name.gsub(/([A-Z]+)([A-Z][a-z])/, '\1_\2')
                               .gsub(/([a-z\d])([A-Z])/, '\1_\2')
                               .downcase

      property_type = get_property_type(parent_type_name, property_name, property)
      is_required = required_fields.include?(property_name)

      if is_required
        "#{snake_name}: #{property_type}"
      else
        "#{snake_name}: Optional[#{property_type}] = None"
      end
    end

    def get_property_type(parent_type_name, property_name, property)
      type = type_for(parent_type_name, property_name, property)

      if type.start_with?('list[')
        list_type = type.match(/list\[(.*?)\]/)
        inner_type = list_type[1]
        if inner_type =~ /^[A-Z]/
          "list[\"#{class_name(inner_type)}\"]"
        else
          "list[#{inner_type}]"
        end
      elsif type =~ /^[A-Z]/
        "\"#{class_name(type)}\""
      else
        type
      end
    end

    def array_type_for(type_name)
      inner_type = if language_translations_for_data_types.values.include?(type_name)
        type_name  # Keep primitive types as is
      else
        class_name(type_name)  # CamelCase for complex types
      end
      "list[#{inner_type}]"
    end

    def format_description(raw_description, indent_string: '    ')
      return '""" """' if raw_description.nil?

      lines = raw_description.split("\n").map { |line|
        if line.strip.empty?
          ""
        else
          "#{indent_string}#{line.rstrip}"
        end
      }

      %("""\n#{lines.join("\n")}\n#{indent_string}""")
    end

    def language_translations_for_data_types
      {
        'integer' => 'int',
        'string' => 'str',
        'boolean' => 'bool',
        'array' => 'list'
      }
    end

    private

    def default_value(parent_type_name, property_name, property)
      if property['type'] == 'string'
        default_value_for_string(parent_type_name, property_name, property)
      elsif property['type'] == 'integer'
        '0'
      elsif property['type'] == 'boolean'
        'False'
      elsif property['type'] == 'array'
        '[]'
      elsif property['$ref']
        "#{class_name(type_for(parent_type_name, nil, property))}()"
      else
        'None'
      end
    end

    def default_value_for_string(parent_type_name, property_name, property)
      if property['enum']
        enum_type_name = type_for(parent_type_name, property_name, property)
        "#{class_name(enum_type_name)}.#{enum_constant(property['enum'][0])}"
      else
        '""'
      end
    end

    def type_for(parent_type_name, property_name, property)
      if property['$ref']
        property_type_from_ref(property['$ref'])
      elsif property['type']
        property_type_from_type(parent_type_name, property_name, property, type: property['type'])
      else
        raise "Property #{property_name} did not define 'type' or '$ref'"
      end
    end

    def property_type_from_type(parent_type_name, property_name, property, type:)
      if type == 'array'
        array_type_for(type_for(parent_type_name, nil, property['items']))
      elsif property['enum']
        enum_name(parent_type_name, property_name, property['enum'])
      else
        language_translations_for_data_types.fetch(type)
      end
    end

    def enum_constant(value)
      value.gsub(/[.\/+]/, '_').downcase
    end

    def enum_name(parent_type_name, property_name, enum)
      "#{class_name(parent_type_name)}#{capitalize(property_name)}".tap do |name|
        @enum_set.add({ name: name, values: enum })
      end
    end

    def property_type_from_ref(ref)
      class_name(ref)
    end

    def class_name(ref)
      return ref if language_translations_for_data_types.values.include?(ref)

      # Remove .json extension if present
      name = ref.sub(/\.json$/, '')
      # Get the basename without path
      name = File.basename(name)
      # Convert each word to proper case, handling camelCase and snake_case
      parts = name.gsub(/[._-]/, '_').split('_').map do |part|
        # Split by any existing camelCase
        subparts = part.scan(/[A-Z][a-z]*|[a-z]+/)
        subparts.map(&:capitalize).join
      end
      # Join all parts to create final CamelCase name
      parts.join
    end
  end
end