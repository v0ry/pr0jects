CC            := clang
CCFLAGS       := -Wall -Wextra -pedantic -std=c17 -g
ASSIGNMENT    := main

.DEFAULT_GOAL := default
.PHONY: default clean bin all run test help


default: help

clean:                ## cleans up project folder
	@printf '[\e[0;36mINFO\e[0m] Cleaning up folder...\n'
	rm -f $(ASSIGNMENT)
	rm -f testreport.html
	rm -rf valgrind_logs

bin:                  ## compiles project to executable binary
	@printf '[\e[0;36mINFO\e[0m] Compiling binary...\n'
	$(CC) $(CCFLAGS) -o $(ASSIGNMENT) $(ASSIGNMENT).c 
	chmod +x $(ASSIGNMENT)

all: clean bin  ## all of the above

run: all              ## runs the project with default config
	@printf '[\e[0;36mINFO\e[0m] Executing binary...\n'
	./$(ASSIGNMENT) wortliste.txt

test: all             ## runs public testcases on the project
	@printf '[\e[0;36mINFO\e[0m] Executing testrunner...\n'
	../../testrunner -c test.toml

help:                 ## prints the help text
	@printf "Usage: make \e[0;36m<TARGET>\e[0m\n"
	@printf "Available targets:\n"
	@awk -F':.*?##' '/^[a-zA-Z_-]+:.*?##.*$$/{printf "  \033[36m%-10s\033[0m%s\n", $$1, $$2}' $(MAKEFILE_LIST)

