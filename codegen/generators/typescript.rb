# frozen_string_literal: true

module Generator
  # Generator::TypeScript
  # Automatic Code generation overrides for the TypeScript programming language
  class TypeScript < Base
    def array_type_for(type_name)
      "readonly #{type_name}[]"
    end

    private

    def select_language_translations_for_data_types(type, property)
      {
        'integer' => 'number',
        'string' => 'string',
        'boolean' => 'boolean'
      }[type]
    end
  end
end
