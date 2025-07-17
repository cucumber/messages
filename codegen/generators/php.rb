# frozen_string_literal: true

module Generator
  # Generator::Php
  # Automatic Code generation overrides for the Php programming language
  class Php < Base
    def array_contents_type(parent_type_name, _property_name, property)
      type_for(parent_type_name, nil, property['items'])
    end

    def array_type_for(_type_name)
      'array'
    end

    def constructor_for(parent_type, property, property_name, schema, arr_name)
      constr = non_nullable_constructor_for(parent_type, property, property_name, schema, arr_name)

      nullable?(property_name, schema) ? "isset($#{arr_name}['#{property_name}']) ? #{constr} : null" : constr
    end

    def default_enum(enum_type_name, property)
      "#{enum_type_name}::#{enum_constant(property['enum'][0])}"
    end

    def enum_name(parent_type_name, property_name, enum)
      enum_type_name = "#{class_name(parent_type_name)}\\#{capitalize(property_name)}"
      @enum_set.add({ name: enum_type_name, values: enum })
      enum_type_name
    end

    def format_description(raw_description, indent_string: '        ')
      return '' if raw_description.nil?

      raw_description
        .split("\n")
        .map(&:strip)
        .filter { |line| line != '*' }
        .map { |line| " * #{line}".rstrip }
        .join("\n#{indent_string}")
    end

    def non_nullable_constructor_for(parent_type, property, property_name, schema, arr_name)
      source = property_name.nil? ? arr_name : "#{arr_name}['#{property_name}']"
      if scalar?(property)
        non_nullable_scalar_constructor(parent_type, property, property_name, source)
      else
        non_nullable_non_scalar_constructor(parent_type, property, property_name, schema, source)
      end
    end

    def nullable?(property_name, schema)
      !(schema['required'] || []).index(property_name)
    end

    def scalar?(property)
      property.key?('type') && select_language_translations_for_data_types(property['type'], property)
    end

    def scalar_type_for(property)
      select_language_translations_for_data_types(property['type'], property)
    end

    private

    def default_value(class_name, property_name, property, schema)
      return 'null' if nullable?(property_name, schema)

      super(class_name, property_name, property)
    end

    def select_language_translations_for_data_types(type, property)
      {
        'string' => 'string',
        'integer' => 'int',
        'boolean' => 'bool'
      }[type]
    end

    def non_nullable_non_scalar_constructor(parent_type, property, property_name, schema, source)
      type = type_for(parent_type, property_name, property)
      if type == 'array'
        constructor = non_nullable_constructor_for(parent_type, property['items'], nil, schema, 'member')
        member_type = (property['items']['type'] ? 'mixed' : 'array')
        "array_values(array_map(fn (#{member_type} $member) => #{constructor}, $#{source}))"
      else
        "#{type_for(parent_type, property_name, property)}::fromArray($#{source})"
      end
    end

    def non_nullable_scalar_constructor(parent_type, property, property_name, source)
      if property['enum']
        "#{enum_name(parent_type, property_name, property['enum'])}::from((#{scalar_type_for(property)}) $#{source})"
      else
        "(#{scalar_type_for(property)}) $#{source}"
      end
    end
  end
end
