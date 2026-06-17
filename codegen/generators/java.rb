# frozen_string_literal: true

module Generator
  # Generator::Java
  # Automatic Code generation overrides for the Java programming language
  class Java < Base
    def array_type_for(type_name)
      "List<#{type_name}>"
    end

    def format_description(raw_description, indent_string: '')
      return '' if raw_description.nil?

      raw_description
        .split("\n")
        .map(&:strip)
        .reject { |line| line == '*' }
        .map { |line| line.rstrip }
        .map { |line| line.empty? ? "<p>" : line }
        .map { |line| " * #{line}"}
        .join("\n#{indent_string}")
    end

    private

    def select_language_translations_for_data_types(type, property)
      if type == 'integer'
        if property['maximum'] and property['maximum'] <= 2147483647
          'Integer'
        else
          'Long'
        end
      elsif type == 'string'
        'String'
      elsif type == 'boolean'
        'Boolean'
      else 
        nil
      end
    end
  end
end
