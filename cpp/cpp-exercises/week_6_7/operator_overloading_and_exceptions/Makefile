.DEFAULT_GOAL := all

clean:
	rm -f frac

bin:
	clang++ -Wall -Wextra -pedantic -o frac Fraction.cpp test.cpp -g -std=c++17

test: bin
	./frac

all: clean bin test
