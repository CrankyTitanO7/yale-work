/*
* File Name: Meal.c
* Author: Ozan Erat
* Date: 2/6/2025
* Version: 1.0.
* Description: 
*   Implementation of Meal for the Cookbook lab
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Meal.h"

int meal_count = 0;

// Internal definition of Meal structure (opaque)
struct meal_instance_t {
    int meal_id;
    char name[50];
};

// Create a Meal with a specified name
Meal* meal_create_with_name(const char *name) {
    Meal *m = malloc(sizeof(Meal));
    meal_assign_id(m);
    strcpy(m->name, name);
    return m;
}

// Destroy a Meal and free its memory
void meal_destroy(Meal *m) {
    free(m);
}

// Print meal details
void meal_print(const Meal *m) {
    printf("%d %s\n", m->meal_id, m->name);
}

// Generate a random meal name from file

// Assign a unique meal ID
void meal_assign_id(Meal *m) {
    m->meal_id = meal_count++;
}
