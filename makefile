CC=gcc
CFLAGS=-ansi -Wall -pedantic -O2

hipo_assembler: main.c
	$(CC) $(CFLAGS) $^ -o $@
