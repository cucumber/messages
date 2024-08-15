defmodule CucumberMessages.MixProject do
  @moduledoc false
  use Mix.Project

  @github "https://github.com/cucumber/messages"

  def project do
    [
      app: :cucumber_messages,
      version: "26.0.0",
      name: "CucumberMessages",
      description: description(),
      package: package(),
      elixir: "~> 1.10",
      start_permanent: Mix.env() == :prod,
      deps: deps()
    ]
  end

  def application do
    [
      extra_applications: [:logger]
    ]
  end

  defp deps do
    [
      {:protox, "~> 1.7.0"},
      {:jason, "~> 1.2"},
      {:ex_doc, "~> 0.34", only: :dev, runtime: false}
    ]
  end

  defp description() do
    "Elixir implementation of the cucumber messages protobuf schema"
  end

  defp package() do
    [
      licenses: ["MIT"],
      source_url: @github,
      links: %{"GitHub" => @github}
    ]
  end
end
