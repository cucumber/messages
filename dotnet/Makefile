schemas = $(shell find ../jsonschema/src -name "*.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require .generate-messages ## Generate c# code based on the schemas found in ../jsonschema and using the scripts in ../jsonschema/scripts for the generation

require: ## Check requirements for the code generation (ruby, csplit and tail are required)
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)
	@csplit --version >/dev/null 2>&1 || (echo "ERROR: csplit is required."; exit 1)
	@tail --version >/dev/null 2>&1 || (echo "ERROR: tail is required."; exit 1)

clean: ## Remove automatically generated files and related artifacts
	rm -rf Cucumber.Messages/generated/*.cs

.generate-messages: $(schemas) ../codegen/codegen.rb ../codegen/templates/dotnet.dotnet.erb ../codegen/templates/dotnet.enum.dotnet.erb
	ruby ../codegen/codegen.rb Generator::Dotnet dotnet.dotnet.erb > Generated.dotnet.tmp
	ruby ../codegen/codegen.rb Generator::Dotnet dotnet.enum.dotnet.erb >> Generated.dotnet.tmp
	csplit --quiet --prefix=Generated --suffix-format=%02d.dotnet.tmp --elide-empty-files Generated.dotnet.tmp /^[A-Za-z.]*[.]cs/ {*}
	rm Generated.dotnet.tmp
	rm -rf Cucumber.Messages/generated/*.cs
	for file in Generated**; do tail -n +2 $$file > Cucumber.Messages/generated/$$(head -n 1 $$file | tr -d '\r\n'); rm $$file; done
