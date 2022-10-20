defmodule CucumberMessages.Attachment do
  defstruct [ body: nil , content_encoding: nil , file_name: nil , media_type: nil , source: nil , test_case_started_id: nil , test_step_id: nil , url: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      body: normal_map["body"],
      content_encoding: normal_map["contentEncoding"],
      file_name: normal_map["fileName"],
      media_type: normal_map["mediaType"],
      source: normal_map["source"],
      test_case_started_id: normal_map["testCaseStartedId"],
      test_step_id: normal_map["testStepId"],
      url: normal_map["url"],
    }
  end
end

defmodule CucumberMessages.Duration do
  defstruct [ seconds: nil , nanos: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      seconds: normal_map["seconds"],
      nanos: normal_map["nanos"],
    }
  end
end

defmodule CucumberMessages.Envelope do
  defstruct [ attachment: nil , gherkin_document: nil , hook: nil , meta: nil , parameter_type: nil , parse_error: nil , pickle: nil , source: nil , step_definition: nil , test_case: nil , test_case_finished: nil , test_case_started: nil , test_run_finished: nil , test_run_started: nil , test_step_finished: nil , test_step_started: nil , undefined_parameter_type: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      attachment: normal_map["attachment"],
      gherkin_document: normal_map["gherkinDocument"],
      hook: normal_map["hook"],
      meta: normal_map["meta"],
      parameter_type: normal_map["parameterType"],
      parse_error: normal_map["parseError"],
      pickle: normal_map["pickle"],
      source: normal_map["source"],
      step_definition: normal_map["stepDefinition"],
      test_case: normal_map["testCase"],
      test_case_finished: normal_map["testCaseFinished"],
      test_case_started: normal_map["testCaseStarted"],
      test_run_finished: normal_map["testRunFinished"],
      test_run_started: normal_map["testRunStarted"],
      test_step_finished: normal_map["testStepFinished"],
      test_step_started: normal_map["testStepStarted"],
      undefined_parameter_type: normal_map["undefinedParameterType"],
    }
  end
end

defmodule CucumberMessages.GherkinDocument do
  defstruct [ uri: nil , feature: nil , comments: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      uri: normal_map["uri"],
      feature: normal_map["feature"],
      comments:     Enum.map(normal_map["comments"] || [], fn item -> CucumberMessages.Comment.decode(item) end),
    }
  end
end

defmodule CucumberMessages.Background do
  defstruct [ location: nil , keyword: nil , name: nil , description: nil , steps: nil , id: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      keyword: normal_map["keyword"],
      name: normal_map["name"],
      description: normal_map["description"],
      steps:     Enum.map(normal_map["steps"] || [], fn item -> CucumberMessages.Step.decode(item) end),
      id: normal_map["id"],
    }
  end
end

defmodule CucumberMessages.Comment do
  defstruct [ location: nil , text: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      text: normal_map["text"],
    }
  end
end

defmodule CucumberMessages.DataTable do
  defstruct [ location: nil , rows: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      rows:     Enum.map(normal_map["rows"] || [], fn item -> CucumberMessages.TableRow.decode(item) end),
    }
  end
end

defmodule CucumberMessages.DocString do
  defstruct [ location: nil , media_type: nil , content: nil , delimiter: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      media_type: normal_map["mediaType"],
      content: normal_map["content"],
      delimiter: normal_map["delimiter"],
    }
  end
end

defmodule CucumberMessages.Examples do
  defstruct [ location: nil , tags: nil , keyword: nil , name: nil , description: nil , table_header: nil , table_body: nil , id: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      tags:     Enum.map(normal_map["tags"] || [], fn item -> CucumberMessages.Tag.decode(item) end),
      keyword: normal_map["keyword"],
      name: normal_map["name"],
      description: normal_map["description"],
      table_header: normal_map["tableHeader"],
      table_body:     Enum.map(normal_map["tableBody"] || [], fn item -> CucumberMessages.TableRow.decode(item) end),
      id: normal_map["id"],
    }
  end
end

defmodule CucumberMessages.Feature do
  defstruct [ location: nil , tags: nil , language: nil , keyword: nil , name: nil , description: nil , children: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      tags:     Enum.map(normal_map["tags"] || [], fn item -> CucumberMessages.Tag.decode(item) end),
      language: normal_map["language"],
      keyword: normal_map["keyword"],
      name: normal_map["name"],
      description: normal_map["description"],
      children:     Enum.map(normal_map["children"] || [], fn item -> CucumberMessages.FeatureChild.decode(item) end),
    }
  end
end

defmodule CucumberMessages.FeatureChild do
  defstruct [ rule: nil , background: nil , scenario: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      rule: normal_map["rule"],
      background: normal_map["background"],
      scenario: normal_map["scenario"],
    }
  end
end

defmodule CucumberMessages.Rule do
  defstruct [ location: nil , tags: nil , keyword: nil , name: nil , description: nil , children: nil , id: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      tags:     Enum.map(normal_map["tags"] || [], fn item -> CucumberMessages.Tag.decode(item) end),
      keyword: normal_map["keyword"],
      name: normal_map["name"],
      description: normal_map["description"],
      children:     Enum.map(normal_map["children"] || [], fn item -> CucumberMessages.RuleChild.decode(item) end),
      id: normal_map["id"],
    }
  end
end

defmodule CucumberMessages.RuleChild do
  defstruct [ background: nil , scenario: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      background: normal_map["background"],
      scenario: normal_map["scenario"],
    }
  end
end

defmodule CucumberMessages.Scenario do
  defstruct [ location: nil , tags: nil , keyword: nil , name: nil , description: nil , steps: nil , examples: nil , id: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      tags:     Enum.map(normal_map["tags"] || [], fn item -> CucumberMessages.Tag.decode(item) end),
      keyword: normal_map["keyword"],
      name: normal_map["name"],
      description: normal_map["description"],
      steps:     Enum.map(normal_map["steps"] || [], fn item -> CucumberMessages.Step.decode(item) end),
      examples:     Enum.map(normal_map["examples"] || [], fn item -> CucumberMessages.Examples.decode(item) end),
      id: normal_map["id"],
    }
  end
end

defmodule CucumberMessages.Step do
  defstruct [ location: nil , keyword: nil , keyword_type: nil , text: nil , doc_string: nil , data_table: nil , id: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      keyword: normal_map["keyword"],
      keyword_type: normal_map["keywordType"],
      text: normal_map["text"],
      doc_string: normal_map["docString"],
      data_table: normal_map["dataTable"],
      id: normal_map["id"],
    }
  end
end

defmodule CucumberMessages.TableCell do
  defstruct [ location: nil , value: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      value: normal_map["value"],
    }
  end
end

defmodule CucumberMessages.TableRow do
  defstruct [ location: nil , cells: nil , id: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      cells:     Enum.map(normal_map["cells"] || [], fn item -> CucumberMessages.TableCell.decode(item) end),
      id: normal_map["id"],
    }
  end
end

defmodule CucumberMessages.Tag do
  defstruct [ location: nil , name: nil , id: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      location: normal_map["location"],
      name: normal_map["name"],
      id: normal_map["id"],
    }
  end
end

defmodule CucumberMessages.Hook do
  defstruct [ id: nil , name: nil , source_reference: nil , tag_expression: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      id: normal_map["id"],
      name: normal_map["name"],
      source_reference: normal_map["sourceReference"],
      tag_expression: normal_map["tagExpression"],
    }
  end
end

defmodule CucumberMessages.Location do
  defstruct [ line: nil , column: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      line: normal_map["line"],
      column: normal_map["column"],
    }
  end
end

defmodule CucumberMessages.Meta do
  defstruct [ protocol_version: nil , implementation: nil , runtime: nil , os: nil , cpu: nil , ci: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      protocol_version: normal_map["protocolVersion"],
      implementation: normal_map["implementation"],
      runtime: normal_map["runtime"],
      os: normal_map["os"],
      cpu: normal_map["cpu"],
      ci: normal_map["ci"],
    }
  end
end

defmodule CucumberMessages.Ci do
  defstruct [ name: nil , url: nil , build_number: nil , git: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      name: normal_map["name"],
      url: normal_map["url"],
      build_number: normal_map["buildNumber"],
      git: normal_map["git"],
    }
  end
end

defmodule CucumberMessages.Git do
  defstruct [ remote: nil , revision: nil , branch: nil , tag: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      remote: normal_map["remote"],
      revision: normal_map["revision"],
      branch: normal_map["branch"],
      tag: normal_map["tag"],
    }
  end
end

defmodule CucumberMessages.Product do
  defstruct [ name: nil , version: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      name: normal_map["name"],
      version: normal_map["version"],
    }
  end
end

defmodule CucumberMessages.ParameterType do
  defstruct [ name: nil , regular_expressions: nil , prefer_for_regular_expression_match: nil , use_for_snippets: nil , id: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      name: normal_map["name"],
      regular_expressions: normal_map["regularExpressions"],
      prefer_for_regular_expression_match: normal_map["preferForRegularExpressionMatch"],
      use_for_snippets: normal_map["useForSnippets"],
      id: normal_map["id"],
    }
  end
end

defmodule CucumberMessages.ParseError do
  defstruct [ source: nil , message: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      source: normal_map["source"],
      message: normal_map["message"],
    }
  end
end

defmodule CucumberMessages.Pickle do
  defstruct [ id: nil , uri: nil , name: nil , language: nil , steps: nil , tags: nil , ast_node_ids: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      id: normal_map["id"],
      uri: normal_map["uri"],
      name: normal_map["name"],
      language: normal_map["language"],
      steps:     Enum.map(normal_map["steps"] || [], fn item -> CucumberMessages.PickleStep.decode(item) end),
      tags:     Enum.map(normal_map["tags"] || [], fn item -> CucumberMessages.PickleTag.decode(item) end),
      ast_node_ids: normal_map["astNodeIds"],
    }
  end
end

defmodule CucumberMessages.PickleDocString do
  defstruct [ media_type: nil , content: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      media_type: normal_map["mediaType"],
      content: normal_map["content"],
    }
  end
end

defmodule CucumberMessages.PickleStep do
  defstruct [ argument: nil , ast_node_ids: nil , id: nil , type: nil , text: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      argument: normal_map["argument"],
      ast_node_ids: normal_map["astNodeIds"],
      id: normal_map["id"],
      type: normal_map["type"],
      text: normal_map["text"],
    }
  end
end

defmodule CucumberMessages.PickleStepArgument do
  defstruct [ doc_string: nil , data_table: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      doc_string: normal_map["docString"],
      data_table: normal_map["dataTable"],
    }
  end
end

defmodule CucumberMessages.PickleTable do
  defstruct [ rows: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      rows:     Enum.map(normal_map["rows"] || [], fn item -> CucumberMessages.PickleTableRow.decode(item) end),
    }
  end
end

defmodule CucumberMessages.PickleTableCell do
  defstruct [ value: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      value: normal_map["value"],
    }
  end
end

defmodule CucumberMessages.PickleTableRow do
  defstruct [ cells: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      cells:     Enum.map(normal_map["cells"] || [], fn item -> CucumberMessages.PickleTableCell.decode(item) end),
    }
  end
end

defmodule CucumberMessages.PickleTag do
  defstruct [ name: nil , ast_node_id: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      name: normal_map["name"],
      ast_node_id: normal_map["astNodeId"],
    }
  end
end

defmodule CucumberMessages.Source do
  defstruct [ uri: nil , data: nil , media_type: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      uri: normal_map["uri"],
      data: normal_map["data"],
      media_type: normal_map["mediaType"],
    }
  end
end

defmodule CucumberMessages.SourceReference do
  defstruct [ uri: nil , java_method: nil , java_stack_trace_element: nil , location: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      uri: normal_map["uri"],
      java_method: normal_map["javaMethod"],
      java_stack_trace_element: normal_map["javaStackTraceElement"],
      location: normal_map["location"],
    }
  end
end

defmodule CucumberMessages.JavaMethod do
  defstruct [ class_name: nil , method_name: nil , method_parameter_types: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      class_name: normal_map["className"],
      method_name: normal_map["methodName"],
      method_parameter_types: normal_map["methodParameterTypes"],
    }
  end
end

defmodule CucumberMessages.JavaStackTraceElement do
  defstruct [ class_name: nil , file_name: nil , method_name: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      class_name: normal_map["className"],
      file_name: normal_map["fileName"],
      method_name: normal_map["methodName"],
    }
  end
end

defmodule CucumberMessages.StepDefinition do
  defstruct [ id: nil , pattern: nil , source_reference: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      id: normal_map["id"],
      pattern: normal_map["pattern"],
      source_reference: normal_map["sourceReference"],
    }
  end
end

defmodule CucumberMessages.StepDefinitionPattern do
  defstruct [ source: nil , type: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      source: normal_map["source"],
      type: normal_map["type"],
    }
  end
end

defmodule CucumberMessages.TestCase do
  defstruct [ id: nil , pickle_id: nil , test_steps: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      id: normal_map["id"],
      pickle_id: normal_map["pickleId"],
      test_steps:     Enum.map(normal_map["testSteps"] || [], fn item -> CucumberMessages.TestStep.decode(item) end),
    }
  end
end

defmodule CucumberMessages.Group do
  defstruct [ children: nil , start: nil , value: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      children:     Enum.map(normal_map["children"] || [], fn item -> CucumberMessages.Group.decode(item) end),
      start: normal_map["start"],
      value: normal_map["value"],
    }
  end
end

defmodule CucumberMessages.StepMatchArgument do
  defstruct [ group: nil , parameter_type_name: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      group: normal_map["group"],
      parameter_type_name: normal_map["parameterTypeName"],
    }
  end
end

defmodule CucumberMessages.StepMatchArgumentsList do
  defstruct [ step_match_arguments: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      step_match_arguments:     Enum.map(normal_map["stepMatchArguments"] || [], fn item -> CucumberMessages.StepMatchArgument.decode(item) end),
    }
  end
end

defmodule CucumberMessages.TestStep do
  defstruct [ hook_id: nil , id: nil , pickle_step_id: nil , step_definition_ids: nil , step_match_arguments_lists: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      hook_id: normal_map["hookId"],
      id: normal_map["id"],
      pickle_step_id: normal_map["pickleStepId"],
      step_definition_ids: normal_map["stepDefinitionIds"],
      step_match_arguments_lists:     case normal_map["stepMatchArgumentsLists"] do
        nil -> nil
        data -> Enum.map(data, fn item -> CucumberMessages.StepMatchArgumentsList.decode(item) end)
    end
    }
  end
end

defmodule CucumberMessages.TestCaseFinished do
  defstruct [ test_case_started_id: nil , timestamp: nil , will_be_retried: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      test_case_started_id: normal_map["testCaseStartedId"],
      timestamp: normal_map["timestamp"],
      will_be_retried: normal_map["willBeRetried"],
    }
  end
end

defmodule CucumberMessages.TestCaseStarted do
  defstruct [ attempt: nil , id: nil , test_case_id: nil , timestamp: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      attempt: normal_map["attempt"],
      id: normal_map["id"],
      test_case_id: normal_map["testCaseId"],
      timestamp: normal_map["timestamp"],
    }
  end
end

defmodule CucumberMessages.TestRunFinished do
  defstruct [ message: nil , success: nil , timestamp: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      message: normal_map["message"],
      success: normal_map["success"],
      timestamp: normal_map["timestamp"],
    }
  end
end

defmodule CucumberMessages.TestRunStarted do
  defstruct [ timestamp: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      timestamp: normal_map["timestamp"],
    }
  end
end

defmodule CucumberMessages.TestStepFinished do
  defstruct [ test_case_started_id: nil , test_step_id: nil , test_step_result: nil , timestamp: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      test_case_started_id: normal_map["testCaseStartedId"],
      test_step_id: normal_map["testStepId"],
      test_step_result: normal_map["testStepResult"],
      timestamp: normal_map["timestamp"],
    }
  end
end

defmodule CucumberMessages.TestStepResult do
  defstruct [ duration: nil , message: nil , status: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      duration: normal_map["duration"],
      message: normal_map["message"],
      status: normal_map["status"],
    }
  end
end

defmodule CucumberMessages.TestStepStarted do
  defstruct [ test_case_started_id: nil , test_step_id: nil , timestamp: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      test_case_started_id: normal_map["testCaseStartedId"],
      test_step_id: normal_map["testStepId"],
      timestamp: normal_map["timestamp"],
    }
  end
end

defmodule CucumberMessages.Timestamp do
  defstruct [ seconds: nil , nanos: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      seconds: normal_map["seconds"],
      nanos: normal_map["nanos"],
    }
  end
end

defmodule CucumberMessages.UndefinedParameterType do
  defstruct [ expression: nil , name: nil ]

  defimpl Jason.Encoder, for: __MODULE__ do
    def encode(value, opts) do
      value
      |> Map.filter(fn {k, v} -> v != nil && k != :__struct__ end)
      |> Enum.map(fn {k, v} -> {CucumberMessages.Helper.lower_camelize(k), v} end)
      |> Enum.into(%{})
      |> Jason.Encode.map(opts)
    end
  end

  def decode(bin) when is_binary(bin), do: bin |> Jason.decode!() |> decode()

  def decode(normal_map) when is_map(normal_map) do
    %__MODULE__{
      expression: normal_map["expression"],
      name: normal_map["name"],
    }
  end
end

