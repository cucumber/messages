# frozen_string_literal: true

module Generator
  # Generator::Cpp
  # Automatic Code generation overrides for the C++ programming language
  class Cpp < Base
    def array_type_for(type_name)
      "std::vector<#{type_name}>"
    end

    def format_description(raw_description, indent_string: '')
      return '' if raw_description.nil?

      raw_description
        .split("\n")
        .map(&:strip)
        .reject { |line| line == '*' }
        .map { |line| "// #{line}".rstrip }
        .join("\n#{indent_string}")
    end

    private

    def select_language_translations_for_data_types(type, property)
      {
        'integer' => 'std::size_t',
        'string' => 'std::string',
        'boolean' => 'bool'
      }[type]
    end
  end
end
