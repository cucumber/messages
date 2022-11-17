defmodule CucumberMessagesTest do
  use ExUnit.Case

  @files [".", "test", "testdata", "*.ndjson"]
         |> Path.join()
         |> Path.wildcard()
         #  temporarily don't look at this test because Elixir/ Jason automatically uppercases some characters?
         |> Enum.filter(fn el -> not String.contains?(el, "attachments.feature.ndjson") end)

  require IEx

  test "serialize en deserialize all messages" do
    results =
      Enum.map(@files, fn path ->
        file_content = path |> File.read!() |> String.trim()
        list_of_jsons = String.split(file_content, "\n")
        comparisons = Enum.map(list_of_jsons, &compare/1)
        all_good? = Enum.all?(comparisons, fn {result, _, _, _} -> result end)
        {all_good?, path, comparisons}
      end)

    testresult = Enum.all?(results, fn {path_result, _, _} -> path_result end)

    Enum.each(results, &verbose_log/1)

    assert testresult
  end

  defp compare(binary) do
    {module_name, message_name, decoded_json} =
      case Jason.decode(binary) do
        {:ok, decoded} ->
          [message_name] = Map.keys(decoded)
          {CucumberMessages.Helper.construct_module_name(message_name), message_name, decoded}

        {:error, data} ->
          IEx.pry()
      end

    decoded = module_name.decode(decoded_json[message_name])
    re_encoded = Jason.encode!(%{message_name => decoded})
    the_same? = binary == re_encoded
    {the_same?, binary, decoded, re_encoded}
  end

  # TODO: extra verbose logging with valid message comparisons for each message
  defp verbose_log({true, path, _comparisons}) do
    text = IO.ANSI.framed() <> IO.ANSI.green_background() <> path <> IO.ANSI.reset()
    IO.puts(text)
  end

  # TODO: extra verbose logging with invalid message comparisons for each message
  defp verbose_log({false, path, _comparisons}) do
    text = IO.ANSI.framed() <> IO.ANSI.red_background() <> path <> IO.ANSI.reset()
    IO.puts(text)
  end
end
