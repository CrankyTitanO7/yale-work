#include <stdio.h>

int main() {
    int x = '#';
    printf("%i", x);

    int f[4][4];
    f[1][1] = '#';
    if (f[1][2] == 35) printf("alive"); else printf("not alive");
    return 1;

    
}