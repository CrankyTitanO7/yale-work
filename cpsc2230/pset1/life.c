/*
Implementations for core functions for Game of Life assignment in CPSC 223 fall 2024

Author: Alan Weide
Modified by: Jaden Lee
Changelog:
 */

#include "life.h"

#include <stdio.h>

#include <stdbool.h>

bool is_alive(int field[ROWS][COLS], size_t i, size_t j)
{
    if (field[i][j] == 35) return true;
    return false;
}

unsigned int num_living_neighbors(int field[ROWS][COLS], size_t i, size_t j)
{
    int ali = 0;

    int imin;
    if (i-1 < 0) imin = 0; else imin = (i-1);
    int imax; 
    if (i+1 >= ROWS) imax = ROWS-1; else imax = (i+1);

    int jmin;
    if (j-1 < 0) jmin = 0; else jmin = (j-1);
    int jmax; 
    if (j+1 >= ROWS) jmax = ROWS-1; else jmax = (j+1);

    
    for (int k = imin; k < imax; k++) {
        for (int m = jmin; k < jmax; j++){
            if (is_alive(field, k, m)) ali ++;
        }
    }
    if (is_alive(field, i, j)) ali --; // do not count self-alive

    return ali;
}

int get_next_state(int field[ROWS][COLS], size_t i, size_t j)
{
    int n = num_living_neighbors(field, i, j);
    // filter out things with too little or much neighbors
    if (n < 2 || n > 3) return DEAD;
    // filter out things that are dead with 2 neighbors
    if (n == 2 && !is_alive(field, i, j)) return DEAD;
    //everything else can be alive (dead with 3 OR alive with 2-3)
    return ALIVE;
}

void compute_next_gen(int cur_field[ROWS][COLS], int next_field[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i ++){
        for (int j = 0; j < COLS; j ++){
            next_field[i][j] = get_next_state(cur_field, i, j);
        }
    }
}
