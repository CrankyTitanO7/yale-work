# what is C?

- imperative programming language 
    - different from functional programming (ie racket, lisp)
    - program is a set of steps (procedures)

- a compiled programming language 
    - different from interpreted languages
    - it is translated first (compiled)

- a high level programming language 
    - lowest of high level
    - control flow constructs, rather than machine instructions

## ~in comparison to Python-like languages~

### C (and c-like language)
- independent of hardware
- explicitly allocate/deallocate
- less built in
- limited standard library

### Higher-Level Language
(Python)
- Independent of hardware
- Memory is managed by the runtime
- Huge collection of builtin constructs and types
- Extensive standard library
- Strong type system


# to compile:
1. gcc factorial.c
    simply run 
    ```bash
    gcc factorial.c
    ```
    in bash. 

    - an open-source program compiler
- see also clang (another compiler from apple that is better)
2. ./a.out
    > this executable cannot be run on other machine.
    note it is in assembly code

> as opposed to python where
> ```bash 
> python factorial.py
> ```

> as opposed to java where
> it is compiled
> then interpreted in the java virtual machine (JVM)

## using gcc
> general usage
>  gcc file.c
>  note that this will output to a.out (which is executable)
12
- gcc -o
    - this flag allows you to name the output file
    - eg gcc -o name file


# parts of a c program
### import
```c 
#include<stdio.h>
```
an import statement

### main()
```c
int main() { ... }
```
the main function

### if/else
```c 
if (condition == true) { 
    ... 
} else {
    ...
}
```
if/else and conditional functions

### input/output
```c
printf("thing to print")
puts("output here") // but i think? it is one character

scanf() // returns one word (stops after whitespace)
getchar() // get one char (stop after char)
```

### while loop
```c
while (condition) { ... }
```
a while loop

## variables
a variable is a name for a location in memory

- manipulating variables changes the state of memory
- each variable has a type
- a variable "char" is in the memory somewhere. it is holding (in unicode binary value):
    - a byte
    - 8 bits

types include: 
- int 
- char
- double
- float
- long
... and eventually, pointer.
Note the absence of boolean!

# abstraction

> “The value of the int variable x is 89”
is actually
“The sequence of bits at the location in memory named x corresponds to the abstract value 89 when interpreted as an int"

# i/o basics
To do any input and output in C, you must use the
stdio (standard input/output) library
```c
#include <stdio.h>
```

- printf and related functions require a format string,
containing conversion specifiers to print text with
potentially-variable fields

Specifiers for outputting numeric types:
- %d: decimal integer (int)
- %Nd (N is an integer)
- %ld: long decimal integer (long)
- %u: unsigned decimal integer (unsigned int)
- %lu: long unsigned decimal integer (unsigned long)
- %c: a single ASCII character (char)
- %lf: long decimal floating-point (double)
    - %N.Mlf (N, M are integers)
- %e: floating-point in exponential notation (double)

note the lack of a string data type.