# frozen_string_literal: true

module Generator
  # Generator::TypeScript
  # Automatic Code generation overrides for TypeScript programming language
  class TypeScript < Base
    def initialize
      language_type_by_schema_type = {
        'integer' => 'number',
        'string' => 'string',
        'boolean' => 'boolean'
      }
      super(language_type_by_schema_type)
    end

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
