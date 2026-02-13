/*
* File Name: ArrayList.h
* Author: Ozan Erat
* Date: 2/6/2025
* Version: 1.0.
* Description: 
*   Interface of ArrayList for the Cookbook lab
*/
#ifndef ArrayList_H
#define ArrayList_H

#include "Meal.h"

// Forward declaration for opaque struct
typedef struct mealList_instance_t MealList;

// Function prototypes for working with MealList
MealList* meallist_create();            // Function to create MealList
void meallist_destroy(MealList *list); // Function to free MealList memory
void meallist_insert_meal(MealList *list, Meal *m);
void meallist_remove_meal(MealList *list, int index);
void meallist_print(const MealList *list);

#endif
