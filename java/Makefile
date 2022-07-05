schemas = $(shell find ../jsonschema -name "*.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require .generate-messages ## Generate java code based on the schemas found in ../jsonschema and using the scripts in ../jsonschema/scripts for the generation

require: ## Check requirements for the code generation (ruby, csplit and tail are required)
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)
	@csplit --version >/dev/null 2>&1 || (echo "ERROR: csplit is required."; exit 1)
	@tail --version >/dev/null 2>&1 || (echo "ERROR: tail is required."; exit 1)

clean: ## Remove automatically generated files and related artifacts
	rm -rf src/generated/java/io/cucumber/messages/types

.generate-messages: $(schemas) ../jsonschema/scripts/codegen.rb ../jsonschema/scripts/templates/java.java.erb ../jsonschema/scripts/templates/java.enum.java.erb
	ruby ../jsonschema/scripts/codegen.rb Java ../jsonschema java.java.erb > Generated.java.tmp
	ruby ../jsonschema/scripts/codegen.rb Java ../jsonschema java.enum.java.erb >> Generated.java.tmp
	csplit --quiet --prefix=Generated --suffix-format=%02d.java.tmp --elide-empty-files Generated.java.tmp /^.*[.]java$$/ {*}
	rm Generated.java.tmp
	rm -rf src/generated/java/io/cucumber/messages/types
	mkdir --parents src/generated/java/io/cucumber/messages/types
	for file in Generated**; do tail -n +2 $$file > src/generated/java/io/cucumber/messages/types/$$(head -n 1 $$file); rm $$file; done
