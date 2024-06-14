# frozen_string_literal: true

module Codegen
  # Codegen::Perl
  # Automatic Code generation overrides for Perl programming language
  class Perl < Base
    def initialize(paths)
      language_type_by_schema_type = {
        'integer' => 'number',
        'string' => 'string',
        'boolean' => 'boolean'
      }

      super(paths, language_type_by_schema_type)
    end

    def array_type_for(type_name)
      "[]#{type_name}"
    end

    def property_type_from_ref(ref)
      "Cucumber::Messages::#{class_name(ref)}"
    end

    def property_type_from_enum(_enum)
      ''
    end

    def format_description(raw_description)
      return '' if raw_description.nil?

      raw_description
    end

    private

    def default_value(parent_type_name, property_name, property)
      if property['type'] == 'string'
        if property['enum']
          "#{property_name.upcase}_#{enum_constant(property['enum'][0])}"
        else
          "''"
        end
      elsif property['type'] == 'boolean'
        "''" # an empty string renders evaluates to false
      elsif property['$ref']
        type = type_for(parent_type_name, nil, property)
        "#{type}->new()"
      else
        super(parent_type_name, property_name, property)
      end
    end
  end
end
