schemas = $(shell find ../jsonschema -name "*.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require lib/cucumber_messages/generated/messages.ex ## Generate elixir code based on the schemas found in ../jsonschema and using `mix generate_json_structs` for the generation

require: ## Check requirements for the code generation (elixir/mix is required)
	@mix --version >/dev/null 2>&1 || (echo "ERROR: elixir/mix is required."; exit 1)

clean: ## Remove automatically generated files and related artifacts
	rm -rf lib/cucumber_messages/generated/messages.ex

lib/cucumber_messages/generated/messages.ex: $(schemas) ../jsonschema/scripts/templates/elixir.erb
	ruby ../jsonschema/scripts/codegen.rb Ruby ../jsonschema elixir.erb > $@
	mix local.hex --force
	mix deps.get
	mix compile
	mix format
