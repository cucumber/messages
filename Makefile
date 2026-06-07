languages = jsonschema cpp dotnet go java javascript perl php python ruby

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: $(patsubst %,generate-%,$(languages)) ## Generate documentation and code for all supported languages
.PHONY: generate

generate-%: %
	$(MAKE) --directory=$< generate
.PHONY: generate-%

clean: $(patsubst %,clean-%,$(languages)) ## Clean generated documentation and code of all supported languages
.PHONY: clean

clean-%: %
	$(MAKE) --directory=$< clean
.PHONY: clean-%
