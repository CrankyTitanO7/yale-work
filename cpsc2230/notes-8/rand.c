#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 2
#define RESIZE_FACTOR 2

int main (int argc, char *argv[]){

    size_t length = 0;
    size_t capacity = INITIAL_CAPACITY; 
    int *array = calloc(capacity, sizeof(int)); // total capacity * size of integers -> a pointer to the heap
    // use * for malloc

    int num;

    while(fscanf(stdin, "%d", &num) == 1) {
        if (num >= 0) {

            if (length >= capacity) {
                capacity *= RESIZE_FACTOR; // update capacity
                array = realloc(array, capacity * sizeof(int)); // RE ALLOC CATION expand the array to new capacity * int
            }   // note that this will also reassign array to point to any new address (if applicable)

            array[length] = num;
            length ++;
        } else if (length > 0) {
            length --;

            if (capacity > INITIAL_CAPACITY && length < capacity/RESIZE_FACTOR) {// SHRINK if over half is empty 
                capacity /= RESIZE_FACTOR;
                array = realloc(array, capacity * sizeof(int));
            }
        }

        fprintf(stdout, "capacity  %-4zu %p ----->[ ", capacity, (void *) array);
        
        for (size_t i = 0; i < length; i++) {
            fprintf(stdout, "%d | ", array[i]);
        }
        for (size_t i = length; i < capacity; i++) {
            fprintf(stdout, " _ |");
        }

        fprintf(stdout, "]\n");
    }

    free(array);
    printf("Done.\n");

    return 0;
}