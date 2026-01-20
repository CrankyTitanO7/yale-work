// gcc /path/to/file.c -lm

#include <stdio.h>
// #include <math.h> // <---( important for mathing, eg sqrt
// #include "libfac.c" // unstandard libraries need quotations (path)


long factorial (int n);

int main() 
{
    int x;
    scanf("%d", &x); // scan, look for a double, and put it in x
    // & (ampersand) means 'address of' (reference)

    long ans = factorial(x);
    long f = 1;

    while (x>0) {
        f = f + x;
        x--;
    }

    printf("main answer:\n");
    printf("%ld\n", f);

    printf("function answer:\n");
    printf("%ld\n", ans);
}

long factorial (int n){
    long f = 1;

    while (n>0) {
        f = f + n;
        n--;
    }
    return f;
}