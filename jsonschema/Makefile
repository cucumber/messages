# The order is significant - ajv needs referenced schemas to be preceded by referencing schemas
schemas = \
	./src/Source.json \
	./src/Location.json \
	./src/Exception.json \
	./src/SourceReference.json \
	./src/Hook.json \
	./src/GherkinDocument.json \
	./src/Meta.json \
	./src/ParameterType.json \
	./src/ParseError.json \
	./src/Pickle.json \
	./src/StepDefinition.json \
	./src/TestCase.json \
	./src/Timestamp.json \
	./src/Attachment.json \
	./src/TestCaseFinished.json \
	./src/TestCaseStarted.json \
	./src/TestRunFinished.json \
	./src/TestRunStarted.json \
	./src/Duration.json \
	./src/TestStepResult.json \
	./src/TestStepFinished.json \
	./src/TestStepStarted.json \
	./src/TestRunHookFinished.json \
	./src/TestRunHookStarted.json \
	./src/UndefinedParameterType.json \
	./src/Envelope.json

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require-doc messages.md relations.md ## Generate markdown documentation using the scripts in ./jsonschema/scripts for the generation

validate: $(schemas) ## Validate the json schemas are valid
	npm install
	node validate.cjs $(patsubst %, %,$(schemas))
.PHONY: validate-schemas

require-doc: ## Check requirements for the generation of the documentation (ruby is required)
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)

messages.md: $(schemas) ../codegen/codegen.rb ../codegen/templates/markdown.md.erb ../codegen/templates/markdown.enum.md.erb
	ruby ../codegen/codegen.rb Generator::Markdown markdown.md.erb > $@
	ruby ../codegen/codegen.rb Generator::Markdown markdown.enum.md.erb >> $@

relations.md: $(schemas) ../codegen/codegen.rb ../codegen/templates/relations.md.erb
	ruby ../codegen/codegen.rb Generator::Markdown relations.md.erb > $@

clean: ## Remove automatically generated documentation files and related artifacts
	rm -f messages.md relations.md
