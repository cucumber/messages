defmodule CucumberMessages.Helper do
  def lower_camelize(atom) when is_atom(atom), do: atom |> Atom.to_string() |> lower_camelize()

  def lower_camelize(string) when is_binary(string) do
    {first_letter, rest} = string |> Macro.camelize() |> String.split_at(1)
    "#{String.downcase(first_letter)}#{rest}"
  end

  def construct_module_name(child) when is_binary(child) do
    last_modulename_part = Macro.camelize(child)
    "Elixir.CucumberMessages.#{last_modulename_part}" |> String.to_atom()
  end
end
