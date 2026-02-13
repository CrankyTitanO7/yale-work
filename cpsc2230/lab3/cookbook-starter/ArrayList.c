/*
* File Name: ArrayList.c
* Author: Ozan Erat
* Date: 2/6/2025
* Version: 1.0.
* Description: 
*   Implementation of ArrayList for the Cookbook lab
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Meal.h"
#include "ArrayList.h"

#define INITIAL_CAPACITY 2  // Initial dynamic array capacity

// Internal definition of MealList structure (opaque)
struct mealList_instance_t {
    int length;
    int capacity;
    Meal **meals;  // Array of pointers to Meal structs
};

// Create and initialize a new MealList with dynamic array of pointers
MealList* meallist_create() {

    // TODO Allocate memory on heap for a MealList and use pointer named 'list'.
    MealList* list = malloc(sizeof(MealList));

    // TODO: Initialize length to 0 and capacity to INITIAL_CAPACITY.
    list->length = 0;
    list->capacity = INITIAL_CAPACITY;

    // TODO Allocate memory on heap for meals array of pointers to Meal structs.  
    list->meals = malloc(sizeof(list->meals) * list->capacity);
    // TODO: return the pointer to the list you just created instead of return 0;
    return list; // you need to change this according to the line above.
}


// Function to insert a meal at the end of the list with dynamic expansion
void meallist_insert_meal(MealList *list, Meal *m) {
  
    // TODO Check if the list is full and expand if needed

    list->meals[list->length] = m;  // Store pointer to Meal
    list->length++;
    if (list->length > list->capacity) {
        list->capacity *= 2;
        list->meals = realloc(list->meals, list->capacity * sizeof(int));
    }
}
// Free the memory used by MealList
void meallist_destroy(MealList *list) {
    for (int i = 0; i < list->length; i++) {
        // TODO Destroy each meal in the list
        free(list->meals[i]);
    }
        // TODO Free the array of pointers
        // TODO Free the MealList itself
        free(list->meals);
        free(list);
}

// Expand the MealList capacity by doubling it
void expand_meallist(MealList *list) {
    printf("\nExpanding capacity from %d to %d\n\n", list->capacity, list->capacity * 2);
    list->capacity *= 2;

   // TODO Reallocate memory for the expanded array of pointers
   list->meals = realloc(list->meals, list->capacity);

    if (list->meals == NULL) {
        fprintf(stderr, "Failed to expand MealList\n");
        exit(EXIT_FAILURE);
    }
}

// TODO:
// Shrink the MealList capacity by halving it. Use realloc for resizing.
void shrink_meallist(MealList *list) {
    // printf("\shrinking capacity from %d to %d\n\n", list->capacity, list->capacity / 2);
    list->capacity /= 2;

   // TODO Reallocate memory for the expanded array of pointers
   list->meals = realloc(list->meals, list->capacity);

    if (list->meals == NULL) {
        fprintf(stderr, "Failed to shrink MealList\n");
        exit(EXIT_FAILURE);
    }
}


// TODO:
// Complete the function below to remove a meal from the list and shrink if needed

void meallist_remove_meal(MealList *list, int index) {
    for (int i = list->length; i < index; i-- ) {
        list->meals[i-1] = list->meals[i];
    }
    list->length --;

    if (list->length <= list->capacity/2) {
        shrink_meallist(list);
    }
}

// Function to print all meals in the list
void meallist_print(const MealList *list) {
    for (int i = 0; i < list->length; i++) {
        meal_print(list->meals[i]);
    }
}
