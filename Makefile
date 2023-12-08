CC=      gcc
LD=      gcc
CFLAGS=  -g -Wall -std=gnu99

HEADERS   = $(wildcard include/*.h) include/token.h
SOURCES   = $(wildcard src/*.c) src/scanner.c src/parser.c
OBJECTS   = $(SOURCES:.c=.o)
TESTS     = $(wildcard run_tests/*.sh)

.PHONY: test

bminor : $(OBJECTS)
	$(LD) -o $@ $^

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

src/scanner.c: scanner.flex
	flex -o $@ $<

src/parser.c include/token.h : parser.bison
	bison --defines=include/token.h --output=src/parser.c $^ -v

test: $(TESTS)
	echo $^ | xargs -n 1 sh

clean: 
	rm -f src/*.o bminor src/scanner.c test/*/*.out test/*/*.s test/*/*.exe src/parser.output src/parser.c include/token.h

