#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* 
     * PART 1: Sizes of Pointer Types and Basic Data Types
     */
    // 1. Print sizes of pointer types
    printf("Size of pointer types on this system:\n");
    printf("  Size of int*    : %zu bytes\n", sizeof(int*));
    printf("  Size of char*   : %zu bytes\n", sizeof(char*));
    printf("  Size of double* : %zu bytes\n\n", sizeof(double*));

    // 2. Print sizes of basic data types for reference
    printf("Size of basic data types:\n");
    printf("  Size of int     : %zu bytes\n", sizeof(int));
    printf("  Size of char    : %zu bytes\n", sizeof(char));
    printf("  Size of double  : %zu bytes\n\n", sizeof(double));

    /* 
     * PART 2: STACK-ALLOCATED ARRAYS
     */
    char   charArray[5]   = {'A', 'B', 'C', 'D', 'E'};
    double doubleArray[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int    intArray[5]    = {10, 20, 30, 40, 50};
    


    // Pointers to the first elements of the stack arrays
    int    *intPtr    = intArray;
    char   *charPtr   = charArray;
    double *doublePtr = doubleArray;

    printf("=== Stack-Allocated Arrays ===\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Iteration %d:\n", i);
        printf("  charPtr   = %p,  *charPtr   = %c\n",   (void*)charPtr, *charPtr);
        printf("  doublePtr = %p,  *doublePtr = %.2f\n", (void*)doublePtr, *doublePtr);
        printf("  intPtr    = %p,  *intPtr    = %d\n\n",   (void*)intPtr, *intPtr);
        
       
        
        // Move to the next element for each pointer
        intPtr++;
        charPtr++;
        doublePtr++;
    }

    /* 
     * PART 3: HEAP-ALLOCATED ARRAYS
     */
    // Allocate memory on the heap
    int    *heapIntPtr    = malloc(5 * sizeof(int));
    char   *heapCharPtr   = malloc(5 * sizeof(char));
    double *heapDoublePtr = malloc(5 * sizeof(double));


    // Initialize the heap-allocated arrays

    // heapIntPtr[0] = 100;  heapIntPtr[1] = 200;  heapIntPtr[2] = 300;  heapIntPtr[3] = 400;  heapIntPtr[4] = 500;
    *heapIntPtr=100; *(heapIntPtr+1)=200; *(heapIntPtr+2)=300; *(heapIntPtr+3)=400; *(heapIntPtr+4)=500;
    
    heapCharPtr[0] = 'X'; heapCharPtr[1] = 'Y'; heapCharPtr[2] = 'Z'; heapCharPtr[3] = 'W'; heapCharPtr[4] = 'Q';
    heapDoublePtr[0] = 10.1; heapDoublePtr[1] = 20.2; heapDoublePtr[2] = 30.3; heapDoublePtr[3] = 40.4; heapDoublePtr[4] = 50.5;

    // Separate pointers to iterate (so we can show pointer incrementing clearly)
    int    *hip = heapIntPtr;
    char   *hcp = heapCharPtr;
    double *hdp = heapDoublePtr;

    printf("=== Heap-Allocated Arrays ===\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Iteration %d:\n", i);
        printf("  hip (int*)    = %p,  *hip    = %d\n",   (void*)hip, *hip);
        printf("  hcp (char*)   = %p,  *hcp    = %c\n",   (void*)hcp, *hcp);
        printf("  hdp (double*) = %p,  *hdp    = %.2f\n\n", (void*)hdp, *hdp);

        // Increment each pointer
        hip++;
        hcp++;
        hdp++;
    }

    // Free heap-allocated memory
    free(heapIntPtr);
    free(heapCharPtr);
    free(heapDoublePtr);

    return 0;
}
