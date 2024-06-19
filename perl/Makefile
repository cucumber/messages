schemas = $(shell find ../jsonschema -name "*.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require lib/Cucumber/Messages.pm ## Generate perl code based on the schemas found in ../jsonschema and using the scripts in ../jsonschema/scripts for the generation

require: ## Check requirements for the code generation (ruby is required)
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)

clean: ## Remove automatically generated files and related artifacts
	rm -f lib/Cucumber/Messages.pm

lib/Cucumber/Messages.pm: $(schemas) ../codegen/codegen.rb ../codegen/templates/perl.pm.erb
	ruby ../codegen/codegen.rb Generator::Perl ../jsonschema perl.pm.erb > $@
