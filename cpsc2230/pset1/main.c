/*
Driver for Game of Life assignment in CPSC 223 Fall 2023

Author: Jaden Lee
*/

#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "constants.h"
#include "life.h"
#include "helpers.h"

int main(int argc, char *argv[])
{
    /*
     * TODO: Accept two command-line arguments, which will appear in the
     * following order:
     * time_steps:
     *      a positive integer describing how many "generations" the simulation
     *      will run for.
     * init:
     *      a string consisting of the characters '0' and '1', of length ROWS * COLS,
     *      representing the initial state for this run of Game of Life.
     */

     int time_steps = atoi(argv[1]);
    //  char* init[] = argv[2];

    /*
     * TODO: Create a new statically-allocated array of size ROWS x COLS
     */

     int arr[ROWS][COLS];
     
     int counter = 0;
     for (int i = 0; i < ROWS; i ++) {
        for (int j = 0; j < COLS; j ++){
            arr[i][j] = convtohash(argv[2][counter]);
            counter++;
        }
     }

    /*
     * TODO: Print the initial values held in the field
     */

     print_initial(arr);
    /*
     * TODO: Run the game time_steps times, printing the field at the end of
     * each step
     */

    //  printf("step complete");
     int i = 1;
     int hold[ROWS][COLS];

     

     memcpy(hold, arr, sizeof(arr)); // set hold to arr

     // debug 
    //  printf("%d", time_steps);

     while (i <= time_steps){
        compute_next_gen(hold, arr);
        print_generation(arr, i);
        memcpy(hold, arr, sizeof(arr));
        i++; 
        // printf("%d", i);
    }
    /*
     * Print "Done." then exit.
     */
    printf("Done.\n");
    return 0;
}
