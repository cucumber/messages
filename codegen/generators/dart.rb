# frozen_string_literal: true

module Generator
  # Generator::Dart
  # Automatic code generation overrides for the Dart programming language
  class Dart < Base
    def array_type_for(type_name)
      "List<#{type_name}>"
    end

    def property_name(name)
      name
    end

    def enum_value_name(value)
      sanitized = enum_constant(value).split('_').map(&:downcase)
      head = sanitized.shift || 'value'
      head + sanitized.map(&:capitalize).join
    end

    def default_enum(enum_type_name, property)
      "#{enum_type_name}.#{enum_value_name(property['enum'][0])}"
    end

    def default_value(parent_type_name, property_name, property)
      return 'const []' if property['items']
      return "const #{type_for(parent_type_name, property_name, property)}()" if property['$ref']

      super
    end

    def enum_name(parent_type_name, property_name, enum)
      "#{class_name(parent_type_name)}#{capitalize(property_name)}".tap do |name|
        @enum_set.add({ name: name, values: enum })
      end
    end

    private

    def each_schema
      @schemas.each do |key, schema|
        yield key, schema
      end
    end

    def part_file_name(ref)
      "#{underscore(class_name(ref))}.g.dart"
    end

    def enums_for(ref, schema)
      (schema['properties'] || {}).filter_map do |property_name, property|
        next unless property['enum']

        {
          name: enum_name(class_name(ref), property_name, property['enum']),
          values: property['enum']
        }
      end
    end

    def select_language_translations_for_data_types(type, _property)
      {
        'integer' => 'int',
        'string' => 'String',
        'boolean' => 'bool'
      }[type]
    end
  end
end
