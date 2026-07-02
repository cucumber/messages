schemas = $(shell find ../jsonschema/src -name "*.schema.json")

.DEFAULT_GOAL = help

INC_DIR = include/generated/cucumber/messages
LIB_DIR = src/generated/cucumber/messages

help: ## Show this help
	@awk 'BEGIN {FS = ":.*##"; printf "\nUsage:\n  make <target>\n\nWhere <target> is one of:\n"} /^[$$()% a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-15s\033[0m %s\n", $$1, $$2 } /^##@/ { printf "\n\033[1m%s\033[0m\n", substr($$0, 5) } ' $(MAKEFILE_LIST)

generate: require .generate-messages ## Generate C++ code based on the schemas found in ../jsonschema and using the scripts in ../jsonschema/scripts for the generation

require: ## Check requirements for the code generation (ruby, csplit and tail are required)
	@ruby --version >/dev/null 2>&1 || (echo "ERROR: ruby is required."; exit 1)
	@csplit --version >/dev/null 2>&1 || (echo "ERROR: csplit is required."; exit 1)
	@tail --version >/dev/null 2>&1 || (echo "ERROR: tail is required."; exit 1)

clean: ## Remove automatically generated files and related artifacts
	rm -rf $(INC_DIR)
	rm -rf $(LIB_DIR)

.generate-messages: $(schemas) ../codegen/codegen.rb ../codegen/templates/cpp.hpp.erb ../codegen/templates/cpp.enum.hpp.erb
	ruby ../codegen/codegen.rb Generator::Cpp cpp.hpp.erb > Generated.hpp.tmp
	ruby ../codegen/codegen.rb Generator::Cpp cpp.enum.hpp.erb >> Generated.hpp.tmp
	csplit --quiet --prefix=Generated --suffix-format=%02d.hpp.tmp --elide-empty-files Generated.hpp.tmp /^[A-Za-z_.]*[.][ch]pp/ {*}
	rm Generated.hpp.tmp

	mkdir -p $(INC_DIR)
	mkdir -p $(LIB_DIR)

	for file in Generated**; do \
		F=$$(head -n 1 $$file | tr -d '\r\n'); \
		if [ -n "$$F" ]; then \
			tail -n +2 $$file > $(INC_DIR)/$$F; \
		fi; \
		rm $$file; \
	done

	mv $(INC_DIR)/*.cpp $(LIB_DIR)/ || true
