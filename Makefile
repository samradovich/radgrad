.PHONY: all configure build clean examples help

all: configure build

configure:
	cmake -B build -S . -G Ninja
	@ln -sf build/compile_commands.json compile_commands.json

build:
	cmake --build build

clean:
	rm -rf build

examples:
	cmake -B build -S . -G Ninja -DRADGRAD_BUILD_EXAMPLES=ON
	@ln -sf build/compile_commands.json compile_commands.json
	cmake --build build

# Pattern rule for running examples
run-%:
	@cmake -B build -S . -G Ninja -DRADGRAD_BUILD_EXAMPLES=ON
	@cmake --build build
	@if [ ! -f build/examples/$* ]; then \
		echo "Error: Example '$*' not found in build/examples/"; \
		exit 1; \
	fi
	@echo "Running $*..."
	@./build/examples/$*

help:
	@echo "Available targets:"
	@echo "  all              - Configure and build the project (default)"
	@echo "  configure        - Run CMake configuration"
	@echo "  build            - Build the project"
	@echo "  clean            - Remove build directory"
	@echo "  examples         - Build all examples"
	@echo "  run-<name>       - Run a specific example"
	@echo "  help             - Show this help message"
	@echo ""
	@echo "Examples:"
	@echo "  make run-basic_usage"
	@echo "  make run-simple_nn"
