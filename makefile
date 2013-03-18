CC=gcc
CFLAGS=-ansi -Wall -pedantic -O2
BIN=bin

RM=rm -f

hipo_assembler: main.o analyzer.o
	$(CC) $(CFLAGS) $^ -o $(BIN)/$@
	@ $(RM) *.o *.gch

main.o: main.c
	$(CC) $(CFLAGS) -c $^

analyzer.o: analyzer.c analyzer.h HIPO.h
	$(CC) $(CFLAGS) -c $^

.PHONY: GDB
GDB: analyzer.c analyzer.h
	$(CC) $(CFLAGS) -g $^ -o $@

clean:
	$(RM) *.o *.gch
