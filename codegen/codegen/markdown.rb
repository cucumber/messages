# frozen_string_literal: true

module Codegen
  # Codegen::Markdown
  # Automatic Code generation overrides for 'Cucumber with Markdown' programming language
  # NB: This is based on the cucumber-js implementation
  class Markdown < Base
    def initialize(paths)
      language_type_by_schema_type = {
        'integer' => 'integer',
        'string' => 'string',
        'boolean' => 'boolean'
      }
      super(paths, language_type_by_schema_type)
    end

    def property_type_from_ref(ref)
      "[#{class_name(ref)}](##{class_name(ref).downcase})"
    end

    def property_type_from_enum(enum)
      "[#{enum}](##{enum.downcase})"
    end

    def array_type_for(type_name)
      "#{type_name}[]"
    end
  end
end
