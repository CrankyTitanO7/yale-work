CC=gcc
CFLAGS=-Wall -pedantic -std=c17 -g3

TSP: location.o tsp.o
	${CC} ${CFLAGS} -o $@ $^ -lm

# test: location.o test.o
# 	${CC} ${CFLAGS} -o $@ $^ -lm

# test.o: location.h tsp.h tsp.o

tsp.o: tsp.c location.h tsp.h

clean: 
	$(RM) TSP test *.o