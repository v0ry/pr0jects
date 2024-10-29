.DEFAULT_GOAL := all

clean:
	rm -f frac

bin:
	clang++ -Wall -Wextra -pedantic -g -std=c++17 -o frac Fraction.cpp test.cpp

test: bin
	./frac

all: clean bin test
