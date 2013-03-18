CC=gcc
CFLAGS=-ansi -Wall -pedantic -O2

RM=rm -f

hipo_assembler: main.o analyzer.o input.o
	$(CC) $(CFLAGS) $^ -o $@
	# @ $(RM) *.o *.gch

main.o: main.c
	$(CC) $(CFLAGS) -c $^

analyzer.o: analyzer.c analyzer.h HIPO.h
	$(CC) $(CFLAGS) -c $^

input.o: input.c input.h
	$(CC) $(CFLAGS) -c $^

clean:
	$(RM) *.o *.gch

.PHONY: GDB
GDB: main.o analyzer.o input.o
	$(CC) $(CFLAGS) $^ -g -o $@
