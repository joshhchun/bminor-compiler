CC=      gcc
LD=      gcc
CFLAGS=  -g -Wall -std=gnu99 

.PHONY: test

bminor : bminor.o
	$(LD) -o $@ $^

bminor.o : bminor.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean: 
	rm -f *.o bminor

test:
	./runtest.sh

