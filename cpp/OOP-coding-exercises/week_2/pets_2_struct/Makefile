CC            := clang++
CCFLAGS       := -Wall -Wextra -pedantic -std=c++17 -g -Wno-unused-parameter
ASSIGNMENT    := pets
.DEFAULT_GOAL := help
TESTRUNNER    := ./../../testrunner -c test.toml

.PHONY: clean bin run test help

clean:                ## cleans up project folder
	@echo "[\033[36mINFO\033[0m] Cleaning up folder..."
	rm -f $(ASSIGNMENT)
	rm -f testreport.html
	rm -rf valgrind_logs

bin:                  ## compiles project to executable binary
	@echo "[\033[36mINFO\033[0m] Compiling binary..."
	$(CC) $(CCFLAGS) -o $(ASSIGNMENT) $(ASSIGNMENT).cpp
	chmod +x $(ASSIGNMENT)

all: clean bin        ## all of the above

run: all              ## runs the project with default config
	@echo "[\033[36mINFO\033[0m] Executing binary..."
	./$(ASSIGNMENT)

test: all             ## runs public testcases on the project compares output line by line
	@echo "[\033[36mINFO\033[0m] Executing testrunner..."
	$(TESTRUNNER)
	@../../.auto-upload.sh

help:                 ## prints the help text
	@echo "Usage: make \033[36m<TARGET>\033[0m"
	@echo "Available targets:"
	@awk -F':.*?##' '/^[a-zA-Z_-]+:.*?##.*$$/{printf "  \033[36m%-10s\033[0m%s\n", $$1, $$2}' $(MAKEFILE_LIST)
