# frozen_string_literal: true

module Generator
  # Generator::Ruby
  # Automatic Code generation overrides for the Ruby programming language
  class Ruby < Base
    def array_type_for(_type_name)
      '[]'
    end

    def format_description(raw_description, indent_string: '    ')
      return '##' if raw_description.nil?

      raw_description
        .split("\n")
        .map { |description_line| line_as_comment(description_line) }
        .push('##')
        .join("\n#{indent_string}")
    end

    private

    def default_value(parent_type_name, property_name, property)
      if property['type'] == 'string'
        default_value_for_string(parent_type_name, property_name, property)
      elsif property['$ref']
        "#{type_for(parent_type_name, nil, property)}.new"
      else
        super(parent_type_name, property_name, property)
      end
    end

    def default_value_for_string(parent_type_name, property_name, property)
      if property['enum']
        enum_type_name = type_for(parent_type_name, property_name, property)
        "#{enum_type_name}::#{enum_constant(property['enum'][0])}"
      else
        "''"
      end
    end

    def line_as_comment(line)
      if line.empty?
        '#'
      else
        "# #{line}"
      end
    end

    def language_translations_for_data_types
      {
        'integer' => 'number',
        'string' => 'string',
        'boolean' => 'boolean'
      }
    end
  end
end
