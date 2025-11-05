all: configure build

build:
	cmake --build build

configure:
	cmake -B build -S . -G Ninja

clean:
	rm -rf build
	rm -f compile_commands.json

run:
	./build/bin/radgrad_app

.PHONY: all clean run build configure