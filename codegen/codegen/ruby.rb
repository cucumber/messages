# frozen_string_literal: true

module Codegen
  # Codegen::Ruby
  # Automatic Code generation overrides for Ruby programming language
  class Ruby < Base
    def initialize(paths)
      language_type_by_schema_type = {
        'integer' => 'number',
        'string' => 'string',
        'boolean' => 'boolean'
      }

      super(paths, language_type_by_schema_type)
    end

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
        if property['enum']
          enum_type_name = type_for(parent_type_name, property_name, property)
          "#{enum_type_name}::#{enum_constant(property['enum'][0])}"
        else
          "''"
        end
      elsif property['$ref']
        type = type_for(parent_type_name, nil, property)
        "#{type}.new"
      else
        super(parent_type_name, property_name, property)
      end
    end

    def line_as_comment(line)
      if line.empty?
        '#'
      else
        "# #{line}"
      end
    end
  end
end
