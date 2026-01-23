#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);
    
    int argies[argc + 1];
    // Loop through all arguments, starting from argv[0]
    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %d", i, argv[i]);
        argies[i] = atoi( argv[i] );
        printf("check -> %d\n", argies[i]);
    }

    printf("%d", 123);

    return 0;
}
