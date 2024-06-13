schemas = $(shell find ../jsonschema -name "*.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require .generate-messages ## Generate ruby code based on the schemas found in ../jsonschema and using the scripts in ../jsonschema/scripts for the generation

require: ## Check requirements for the code generation (ruby, csplit and tail are required)
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)
	@csplit --version >/dev/null 2>&1 || (echo "ERROR: csplit is required."; exit 1)
	@tail --version >/dev/null 2>&1 || (echo "ERROR: tail is required."; exit 1)

clean: ## Remove automatically generated files and related artifacts
	find ./lib/cucumber/messages/*.rb ! -name 'message.rb' -type f -exec rm -f {} +

.generate-messages: $(schemas) ../jsonschema/scripts/codegen.rb ../jsonschema/scripts/templates/ruby.rb.erb ../jsonschema/scripts/templates/ruby.enum.rb.erb
	ruby ../jsonschema/scripts/codegen.rb Ruby ../jsonschema ruby.rb.erb > Generated.rb.tmp
	ruby ../jsonschema/scripts/codegen.rb Ruby ../jsonschema ruby.enum.rb.erb >> Generated.rb.tmp
	csplit --quiet --prefix=Generated --suffix-format=%02d.rb.tmp --elide-empty-files Generated.rb.tmp /^[A-Za-z_.]*[.]rb/ {*}
	rm Generated.rb.tmp
	for file in Generated**; do tail -n +2 $$file > ./lib/cucumber/messages/$$(head -n 1 $$file | tr -d '\r\n'); rm $$file; done
