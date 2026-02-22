#include <stdio.h>
#include "string.h"


int main (void) {
    char m[] = "mic\0hael\0";
    printf("%c\n", m[0]);
    printf("%c\n", m[1]);
    printf("%c\n", *(m+1));
    printf("%s", m);


    //q1
    // char *nov19 = "IAD-IAH-SCL";
    // strcpy(nov19, "DCA");
    // fprintf(stdout, "%s\n", nov19);

    // q2
    // char cig15[] = ""; // initialize size of 1
    // strcpy(cig15, "BOS-NRT");
    // strcat(cig15, "-TPE");
    // fprintf(stdout, "%s\n", cig15);

    // // q5
    // char aug23[16];
    // strcpy(aug23, "BWI-ORD");
    // strcat(aug23 + 3, "-DEN-PAE");
    // fprintf(stdout, "%s\n", aug23);

    // q6
    // q7
    // q12
    // q13 (partial)
    // q14
    // q15 (partial)

    return 0;
}