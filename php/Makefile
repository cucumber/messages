schemas = $(shell find ../jsonschema -name "*.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require build/messages.php ## Generate php code based on the schemas found in ../jsonschema and using the scripts in ../jsonschema/scripts for the generation

require: ## Check requirements for the code generation (ruby, php, csplit, tail and php-cs-fixer are required)
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)
	@csplit --version >/dev/null 2>&1 || (echo "ERROR: csplit is required."; exit 1)
	@tail --version >/dev/null 2>&1 || (echo "ERROR: tail is required."; exit 1)

clean: ## Remove automatically generated files and related artifacts
	rm -rf build/messages.php
	rm -rf build/Generated*.php.tmp
	rm -rf src-generated/*

build/messages.php: $(schemas) ../codegen/codegen.rb ../jsonschema/scripts/templates/php.php.erb ../jsonschema/scripts/templates/php.enum.php.erb
	mkdir -p build
	ruby ../codegen/codegen.rb Php ../jsonschema php.php.erb > build/messages.php
	ruby ../codegen/codegen.rb Php ../jsonschema php.enum.php.erb >> build/messages.php
	csplit --quiet --prefix=build/Generated --suffix-format=%02d.php.tmp --elide-empty-files build/messages.php /^[A-Za-z/.]*[.]php/ {*}
	rm -rf src-generated/*
	for file in build/Generated**; do mkdir -p src-generated/$$(head -n 1 $$file | sed 's/[^/]*.php[\r]*$$//'); done
	for file in build/Generated**; do tail -n +2 $$file > src-generated/$$(head -n 1 $$file | tr -d '\r\n'); rm $$file; done
