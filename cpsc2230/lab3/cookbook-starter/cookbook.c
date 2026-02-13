/*
* File Name: cookbook.c
* Author: Ozan Erat
* Date: 2/6/2025
* Version: 1.0.
* Description: 
*   The driver for the Cookbook lab
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Meal.h"

int main() {
    // Create a dynamic MealList
    MealList *mealList = meallist_create();

    // Open meal_names.txt file
    FILE *file = fopen("meal_names.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening meal_names.txt\n");
        meallist_destroy(mealList);
        return EXIT_FAILURE;
    }

    // Read meal names from the file, create each Meal, store it, and print
    char name[50];
    while (fgets(name, sizeof(name), file) != NULL) {
        name[strcspn(name, "\n")] = 0; // Remove newline character
        if (strlen(name) > 0) {  // Only add meals with valid names
            Meal *meal = meal_create_with_name(name);  // Create meal dynamically
            meallist_insert_meal(mealList, meal);

            // Print the meal immediately after storing it
            printf("Adding meal to cookbook: ");
            meal_print(meal);
        }
    }
        /********************OPTIONAL CHALLENGE********************/
    // TODO 1. Complete the meallist_remove_meal() function in ArrayList.c and uncomment the following lines below.
    // TODO 2. Also, complete shrink_meallist() function to shrink the array.

    //meallist_remove_meal(mealList, 1);  // Remove the second meal
    //meallist_print(mealList);  // Print the MealList after removal
    
    
    // Close the file
    fclose(file);

    // Free the MealList
    meallist_destroy(mealList);

    return 0;
}
