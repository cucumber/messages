module Generator
  # Generator::Dotnet
  # Automatic Code generation overrides for the .NET programming language
  class Dotnet < Base
    def array_type_for(type_name)
      "List<#{type_name}>"
    end

    def format_description(raw_description, indent_string: '')
      return '' if raw_description.nil?

      raw_description
        .split("\n")
        .map { |line| line.strip }
        .filter { |line| line != '*' }
        .map { |line| " * #{line}".rstrip }
        .join("\n#{indent_string}")
    end

    private

    def language_translations_for_data_types
      {
        'integer' => 'long',
        'string' => 'string',
        'boolean' => 'bool'
      }
    end
  end
end
