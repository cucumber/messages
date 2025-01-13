schemas = $(shell find ../jsonschema -name "*.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require src/cucumber_messages/_messages.py src/cucumber_messages/_message_enums.py

require: ## Check requirements for the code generation (ruby is required)
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)

clean: ## Remove automatically generated files and related artifacts
	rm -f src/cucumber_messages/_messages.py
	rm -f src/cucumber_messages/_message_enums.py

src/cucumber_messages/_messages.py: $(schemas) ../codegen/codegen.rb ../codegen/templates/python.py.erb
	ruby ../codegen/codegen.rb Generator::Python python.py.erb > $@

src/cucumber_messages/_message_enums.py: $(schemas) ../codegen/codegen.rb ../codegen/templates/python.enum.py.erb
	ruby ../codegen/codegen.rb Generator::Python python.enum.py.erb > $@
