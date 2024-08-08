class Dotnet < Codegen
  def initialize(paths)
    language_type_by_schema_type = {
      'integer' => 'long',
      'string' => 'string',
      'boolean' => 'bool',
    }

    super(paths, language_type_by_schema_type)
  end

  def array_type_for(type_name)
    "List<#{type_name}>"
  end

  def format_description(raw_description, indent_string: '')
    return '' if raw_description.nil?

    raw_description
      .split("\n")
      .map { |line| line.strip }
      .filter { |line| line != '*' }
      .map { |line| " * #{line}".rstrip() }
      .join("\n#{indent_string}")
  end
end
