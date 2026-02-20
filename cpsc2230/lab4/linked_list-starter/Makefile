# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -g

# Default target: build everything

all: main test
# --- main program ---

main: main.o linked_list.o
	$(CC) $(CFLAGS) -o main main.o linked_list.o

main.o: main.c linked_list.h
	$(CC) $(CFLAGS) -c main.c

linked_list.o: linked_list.c linked_list.h
	$(CC) $(CFLAGS) -c linked_list.c


test: unittest.o linked_list.o
	$(CC) $(CFLAGS) -o test unittest.o linked_list.o

unittest.o: unittest.c linked_list.h
	$(CC) $(CFLAGS) -c unittest.c


# --- cleanup ---

clean:
	rm -f *.o main vgcore.*

# --- other shortcuts ---

run: $(main)
	./main

valgrind: $(main)
	valgrind -s --leak-check=full  ./main

.PHONY: all clean run valgrind
