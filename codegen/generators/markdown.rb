# frozen_string_literal: true

module Generator
  # Generator::Markdown
  # Automatic Code generation overrides for the 'Cucumber with Markdown' programming language
  # NB: This is based on the cucumber-js implementation
  class Markdown < Base
    def initialize
      # This path is different because the make task is ran from the TLD, not a language specific one
      super(paths: Dir['./jsonschema/*.json'])
    end

    def array_type_for(type_name)
      "#{type_name}[]"
    end

    def property_type_from_enum(enum)
      "[#{enum}](##{enum.downcase})"
    end

    def property_type_from_ref(ref)
      "[#{class_name(ref)}](##{class_name(ref).downcase})"
    end

    private

    def language_translations_for_data_types
      {
        'integer' => 'integer',
        'string' => 'string',
        'boolean' => 'boolean'
      }
    end
  end
end
