CC=      gcc
LD=      gcc
CFLAGS=  -g -Wall -std=gnu99 

.PHONY: test

bminor : bminor.o scanner.o parser.o
	$(LD) -o $@ $^

scanner.o: scanner.c token.h
	$(CC) $(CFLAGS) -c $< -o $@

bminor.o : bminor.c token.h
	$(CC) $(CFLAGS) -c $< -o $@

scanner.c: scanner.flex
	flex -o $@ $<

parser.c token.h: parser.bison
	bison --defines=token.h --output=parser.c $^ -v

parser.o: parser.c token.h
	$(CC) $(CFLAGS) -c $^


clean: 
	rm -f *.o bminor scanner.c test/*/*.out

test:
	./run_encoder_tests.sh
	./run_scanner_tests.sh
	./run_parser_tests.sh
