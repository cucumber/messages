# frozen_string_literal: true

module Generator
  # Generator::Go
  # Automatic Code generation overrides for the Go programming language
  class Go < Base
    def array_type_for(type_name)
      "[]#{type_name}"
    end

    def property_type_from_ref(ref)
      "*#{class_name(ref)}"
    end

    private

    def language_translations_for_data_types
      {
        'integer' => 'int64',
        'string' => 'string',
        'boolean' => 'bool'
      }
    end
  end
end
