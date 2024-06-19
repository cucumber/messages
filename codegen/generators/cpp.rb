# frozen_string_literal: true

module Generator
  # Generator::Typescript
  # Automatic Code generation overrides for C++ programming language
  class Cpp < Base
    def initialize(paths)
      language_type_by_schema_type = {
        'integer' => 'std::size_t',
        'string' => 'std::string',
        'boolean' => 'bool'
      }
      super(language_type_by_schema_type)
    end

    def array_type_for(type_name)
      "std::vector<#{type_name}>"
    end

    def format_description(raw_description, indent_string: '')
      return '' if raw_description.nil?

      raw_description
        .split("\n")
        .map(&:strip)
        .filter { |line| line != '*' }
        .map { |line| "// #{line}".rstrip }
        .join("\n#{indent_string}")
    end
  end
end
