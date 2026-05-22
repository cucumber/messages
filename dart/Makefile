schemas = $(shell find ../jsonschema/src -name "*.schema.json")

.DEFAULT_GOAL = help

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require lib/src/messages.dart .generate-messages ## Generate Dart code from JSON schemas

require: ## Check requirements for generation and checks
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)
	@dart --version >/dev/null 2>&1 || (echo "ERROR: dart is required."; exit 1)

clean: ## Remove automatically generated files and artifacts
	rm -f lib/src/messages.dart lib/src/*.g.dart

lib/src/messages.dart: $(schemas) ../codegen/codegen.rb ../codegen/templates/dart.index.dart.erb
	ruby ../codegen/codegen.rb Generator::Dart dart.index.dart.erb > $@

.generate-messages: $(schemas) ../codegen/codegen.rb ../codegen/templates/dart.dart.erb
	ruby ../codegen/codegen.rb Generator::Dart dart.dart.erb > Generated.dart.tmp
	ruby -e "input = File.readlines('Generated.dart.tmp', chomp: true); current = nil; lines = []; flush = lambda { next unless current; File.write(File.join('lib/src', current), lines.join(\"\\n\") + \"\\n\"); lines = [] }; input.each do |line| if line.end_with?('.g.dart') && !line.include?(' '); flush.call; current = line; else; lines << line; end; end; flush.call"
	rm -f Generated.dart.tmp
	dart format lib/src/messages.dart lib/src/*.g.dart
