# frozen_string_literal: true

module Generator
  # Generator::Go
  # Automatic Code generation overrides for Go programming language
  class Go < Base
    def initialize(paths)
      language_type_by_schema_type = {
        'integer' => 'int64',
        'string' => 'string',
        'boolean' => 'bool'
      }
      super(paths, language_type_by_schema_type)
    end

    def array_type_for(type_name)
      "[]#{type_name}"
    end

    def property_type_from_ref(ref)
      "*#{class_name(ref)}"
    end
  end
end
