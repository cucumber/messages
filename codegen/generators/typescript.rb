# frozen_string_literal: true

module Generator
  # Generator::TypeScript
  # Automatic Code generation overrides for the TypeScript programming language
  class TypeScript < Base
    def array_type_for(type_name)
      "readonly #{type_name}[]"
    end

    private

    def language_translations_for_data_types
      {
        'integer' => 'number',
        'string' => 'string',
        'boolean' => 'boolean'
      }
    end
  end
end
