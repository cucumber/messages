# frozen_string_literal: true

module Generator
  # Generator::Typescript
  # Automatic Code generation overrides for Java programming language
  class Java < Base
    def initialize(paths)
      language_type_by_schema_type = {
        'integer' => 'Long',
        'string' => 'String',
        'boolean' => 'Boolean'
      }

      super(paths, language_type_by_schema_type)
    end

    def array_type_for(type_name)
      "java.util.List<#{type_name}>"
    end

    def format_description(raw_description, indent_string: '')
      return '' if raw_description.nil?

      raw_description
        .split("\n")
        .map(&:strip)
        .filter { |line| line != '*' }
        .map { |line| " * #{line}".rstrip }
        .join("\n#{indent_string}")
    end
  end
end
