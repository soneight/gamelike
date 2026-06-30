.PHONY: usage cmake ninja clean build allin
# commands
usage:
	@cat Makefile.usage.txt
cmake:
	@echo "configuring project"
	@cmake --preset default
ninja:
	@echo "generating project"
	@cmake --build --preset default
clean:
	@echo "cleaning build directory"
	@rm -rf build/
	@git restore build/.gitignore
build:
	@echo "configuring and generating project"
	@make cmake
	@make ninja
allin:
	@echo "cleaning build directory and then configuring and generating project"
	@make clean
	@make build
