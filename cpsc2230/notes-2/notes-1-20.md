# c numeric types

- denominator is representable in binary, is ok to use double

# typecasting

say that i have values in the type float, and it overloads in operation, and THEN cast it to double, the value will still be inaccurate. 

types of numbers:
- int (small, no decimal)
- float (small, some decimal)
- double (big precise decimals)

## int quirks
- overload causes negative values
- fraction means floor
- division by 0 causes a crash! 

## float quirks
- overload causes inf
- division by 0 similarly gets inf

## double quirks
- imaginary numbers: 

# errors
- core dumped : originates from magnetic cores dumping all their values before killing themselves

# important tips!

during compilation, we can add libraries:

gcc /path/to/file.c -lm 

and also 
```c 
#include <math.h> 
```

^^ you must use this to do math!!


# functions

return-type function-name(parameter-type paramaters) {
    ... 
    return value;
}

to use: you need to put it above main function, or add definition there

```c 
double colatitude(double int);
int main(){
    double co = colatitude(41.30815);
    printf("%lf\n", co)
}
```

# using libraries

```c
 #include <math.h> // <---( important for mathing, eg sqrt
 #include "libfac.c" // unstandard libraries need quotations (path)
 ```

 note that normally
 ```bash 
 gcc /path/to/file.c
 ```
 is normally ok. but when using a custom (imported) library with .h and .c files, you must do 
 include listed above, and
 ```bash
 gcc /path/to/program.c /path/to/include.c
 ``` 
 AND you must include the header in the c file:
 ```c 
 #include "path/to/include.h"
 ```

 