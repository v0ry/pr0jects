SHELL := /bin/bash
.PHONY: test, valgrind, clean

test:
	rm -rf quib_test __test/staging
	mkdir -p __test/staging
	rsync -aq --ignore-missing-args ./{*.cpp,*.h} framework __test/staging
	mkdir -p test_output
	rm -f test_output/*
	python3 ./run-tests.py
	rm -rf quib_test __test

quib: *.cpp *.h
	g++ -std=c++20 -Wall -Wextra -Werror -Og -fno-lto -g *.cpp framework/*.cpp framework/test-parser.a -o quib

analyze: *.cpp *.h
	cppcheck --std=c++20 --suppress=missingIncludeSystem --suppress=unusedFunction --enable=all *.cpp

clean:
	rm -rf quib quib_test test_output __test
