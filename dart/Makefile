schemas = $(shell find ../jsonschema/src -name "*.schema.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require lib/src/messages.dart .generate-messages ## Generate Dart code from JSON schemas

require: ## Check requirements for code generation
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)

clean: ## Remove automatically generated files and artifacts
	rm -f lib/src/messages.dart lib/src/*.g.dart

lib/src/messages.dart: $(schemas) ../codegen/codegen.rb ../codegen/templates/dart.index.dart.erb
	ruby ../codegen/codegen.rb Generator::Dart dart.index.dart.erb > $@

.generate-messages: $(schemas) ../codegen/codegen.rb ../codegen/templates/dart.dart.erb ../codegen/templates/dart.index.dart.erb
	ruby ../codegen/codegen.rb Generator::Dart dart.dart.erb > Generated.dart.tmp
	csplit --quiet --prefix=Generated --suffix-format=%02d.dart.tmp --elide-empty-files Generated.dart.tmp /^[a-z0-9_]*\.g\.dart/ {*}
	rm Generated.dart.tmp
	for file in Generated**; do tail -n +2 $$file > lib/src/$$(head -n 1 $$file | tr -d '\r\n'); rm $$file; done
