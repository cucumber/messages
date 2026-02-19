schemas = $(shell find ./src -name "*.schema.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require-doc messages.schema.json messages.md relations.md ## Generate bundled schema and documentation

messages.schema.json: $(schemas) bundle.mjs package.json
	npm install
	node bundle.mjs

require-doc: ## Check requirements for documentation generation
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)

messages.md: $(schemas) ../codegen/codegen.rb ../codegen/templates/markdown.md.erb ../codegen/templates/markdown.enum.md.erb
	ruby ../codegen/codegen.rb Generator::Markdown markdown.md.erb > $@
	ruby ../codegen/codegen.rb Generator::Markdown markdown.enum.md.erb >> $@

relations.md: $(schemas) ../codegen/codegen.rb ../codegen/templates/relations.md.erb
	ruby ../codegen/codegen.rb Generator::Markdown relations.md.erb > $@

clean: ## Remove generated files
	rm -f messages.md relations.md messages.schema.json
