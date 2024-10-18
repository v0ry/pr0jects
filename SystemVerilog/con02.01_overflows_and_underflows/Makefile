CC      := gcc
CFLAGS  := -Wall -Wextra

SOURCES := $(wildcard *.c)
BASE    := $(basename $(SOURCES))

all: build

build: $(BASE).elf

$(BASE).elf: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: run
run: build
	./$(BASE).elf

.PHONY: clean
clean:
	rm -f $(BASE).elf
