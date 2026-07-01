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

    def enum_name(parent_type_name, property_name, enum)
      "#{class_name(parent_type_name)}#{capitalize(property_name)}".tap do |name|
        @enum_set.add({ name: name, values: enum })
      end
    end

    def class_doc_comment(type_name, schema, indent_string: '')
      description = [
        "Generated Dart representation of the [#{type_name} message](#{schema_url(type_name)}) in Cucumber's [message protocol](https://github.com/cucumber/messages).",
        schema['description']
      ].compact.join("\n\n")

      doc_comment(description, indent_string: indent_string)
    end

    def enum_doc_comment(enum, indent_string: '')
      description = enum[:description] || "Values for the `#{enum[:property_name]}` property."

      doc_comment(description, indent_string: indent_string)
    end

    def enum_value_doc_comment(value, indent_string: '')
      doc_comment("The `#{value}` value.", indent_string: indent_string)
    end

    def property_doc_comment(property_name, property, indent_string: '')
      description = property['description'] || "The `#{property_name}` property."

      doc_comment(description, indent_string: indent_string)
    end

    def doc_comment(raw_description, indent_string: '')
      return '' if raw_description.nil? || raw_description.empty?

      raw_description
        .split("\n")
        .map(&:rstrip)
        .map { |line| line.empty? ? '///' : "/// #{line}" }
        .map { |line| "#{indent_string}#{line}" }
        .join("\n")
    end

    def schema_url(type_name)
      "https://github.com/cucumber/messages/blob/main/jsonschema/src/#{type_name}.schema.json"
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
          values: property['enum'],
          property_name: property_name,
          description: property['description']
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
