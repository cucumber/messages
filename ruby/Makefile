schemas = $(shell find ../jsonschema -name "*.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require lib/cucumber/messages.dtos.rb lib/cucumber/messages.deserializers.rb ## Generate ruby code based on the schemas found in ../jsonschema and using the scripts in ../jsonschema/scripts for the generation

require: ## Check requirements for the code generation (ruby is required)
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)

clean: ## Remove automatically generated files and related artifacts
	rm -f lib/cucumber/messages.dtos.rb
	rm -f lib/cucumber/messages.deserializers.rb

lib/cucumber/messages.dtos.rb: $(schemas) ../jsonschema/scripts/codegen.rb ../jsonschema/scripts/templates/ruby.rb.erb ../jsonschema/scripts/templates/ruby.enum.rb.erb
	ruby ../jsonschema/scripts/codegen.rb Ruby ../jsonschema ruby.rb.erb > $@
	ruby ../jsonschema/scripts/codegen.rb Ruby ../jsonschema ruby.enum.rb.erb >> $@

lib/cucumber/messages.deserializers.rb: $(schemas) ../jsonschema/scripts/codegen.rb ../jsonschema/scripts/templates/ruby_deserializers.rb.erb
	ruby ../jsonschema/scripts/codegen.rb Ruby ../jsonschema ruby_deserializers.rb.erb > $@
