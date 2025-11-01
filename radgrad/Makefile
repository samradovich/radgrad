all:
	mkdir -p build
	cmake -B build -G Ninja
	cmake --build build

clean:
	rm -rf build

run:
	./build/bin/radgrad_app

.PHONY: all clean run