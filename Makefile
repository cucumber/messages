# The order is significant - ajv needs referenced schemas to be preceded by referencing schemas
schemas = \
	./jsonschema/Source.json \
	./jsonschema/Attachment.json \
	./jsonschema/Location.json \
	./jsonschema/Exception.json \
	./jsonschema/SourceReference.json \
	./jsonschema/Hook.json \
	./jsonschema/GherkinDocument.json \
	./jsonschema/Meta.json \
	./jsonschema/ParameterType.json \
	./jsonschema/ParseError.json \
	./jsonschema/Pickle.json \
	./jsonschema/StepDefinition.json \
	./jsonschema/TestCase.json \
	./jsonschema/Timestamp.json \
	./jsonschema/TestCaseFinished.json \
	./jsonschema/TestCaseStarted.json \
	./jsonschema/TestRunFinished.json \
	./jsonschema/TestRunStarted.json \
	./jsonschema/Duration.json \
	./jsonschema/TestStepResult.json \
	./jsonschema/TestStepFinished.json \
	./jsonschema/TestStepStarted.json \
	./jsonschema/GlobalHookFinished.json \
	./jsonschema/GlobalHookStarted.json \
	./jsonschema/UndefinedParameterType.json \
	./jsonschema/Envelope.json

languages = cpp go java javascript perl php ruby dotnet

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate-all: generate-code generate-doc ## Generate documentation and code for all supported languages
.PHONY: generate-all

generate-code: $(patsubst %,generate-%,$(languages)) ## Generate code for all supported languages
.PHONY: generate-languages

generate-doc: require-doc messages.md ## Generate markdown documentation using the scripts in ./jsonschema/scripts for the generation

validate: $(schemas) ## Validate the json schemas are valid
	npm install
	node validate.cjs $(patsubst %, %,$(schemas))
.PHONY: validate-schemas

require-doc: ## Check requirements for the generation of the documentation (ruby is required)
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)

clean-doc: ## Remove automatically generated documentation files and related artifacts
	rm -f messages.md

clean-all: clean-doc $(patsubst %,clean-%,$(languages)) ## Clean generated documentation and code of all supported languages
.PHONY: clean-all

messages.md: $(schemas) ./codegen/codegen.rb ./codegen/templates/markdown.md.erb ./codegen/templates/markdown.enum.md.erb
	ruby ./codegen/codegen.rb Generator::Markdown markdown.md.erb > $@
	ruby ./codegen/codegen.rb Generator::Markdown markdown.enum.md.erb >> $@

generate-%: %
	cd $< && make generate
.PHONY: generate-%

clean-%: %
	cd $< && make clean
.PHONY: clean-%
