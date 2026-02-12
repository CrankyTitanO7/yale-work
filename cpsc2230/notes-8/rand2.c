#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 2
#define RESIZE_FACTOR 2

typedef struct { 
    size_t length;
    size_t capacity;
    int *array;
}list;

list *list_create() 
{
    list *lst = malloc(sizeof(list)); // list is a data type now
    lst -> capacity = INITIAL_CAPACITY;
    lst -> length = 0;
    lst -> array = calloc(lst->capacity, sizeof(int));
}

void list_append(list *lst, int val) {
    if (lst->length >= lst->capacity) {
                lst->capacity *= RESIZE_FACTOR; // update capacity
                lst->array = realloc(lst->array, lst->capacity * sizeof(int)); // RE ALLOC CATION expand the array to new capacity * int
            }   // note that this will also reassign array to point to any new address (if applicable)

            lst->array[lst->length] = val;
            lst->length ++;
}

int list_remove(list *lst, int val) {
    lst->length --;
    lst->array[lst->length];

    int last = lst->array[lst->length];

    if (lst->capacity > INITIAL_CAPACITY && lst->length < lst->capacity/RESIZE_FACTOR) {// SHRINK if over half is empty 
        lst->capacity /= RESIZE_FACTOR;
        lst->array = realloc(lst->array, lst->capacity * sizeof(int));
    }
    return last;
}

void list_destroy(list *lst) {
    free(lst->array);
    free(lst);
}

int main (int argc, char *argv[]){
    

    list *lst = list_create();

    int num = 0;

    while(fscanf(stdin, "%d", &num) == 1) {
        if (num >= 0) {

            list_append(lst, num);

            
        } else if (lst->length > 0) {
            list_remove(lst, num);
            
        }

        fprintf(stdout, "capacity  %-4zu %p ----->[ ", lst->capacity, (void *) lst->array);
        
        for (size_t i = 0; i < lst->length; i++) {
            fprintf(stdout, "%d | ", lst->array[i]);
        }
        for (size_t i = lst->length; i < lst->capacity; i++) {
            fprintf(stdout, " _ |");
        }

        fprintf(stdout, "]\n");
    }

    list_destroy(lst);
    printf("Done.\n");

    return 0;
}