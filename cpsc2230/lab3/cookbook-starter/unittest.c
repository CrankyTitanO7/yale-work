#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "ArrayList.h"
#include "Meal.h"

void test_meallist_create() {
    MealList *list = meallist_create();
    assert(list != NULL);  // Ensure list is created
    printf("test_meallist_create passed\n");
    meallist_destroy(list);
}

void test_meal_create_with_name() {
    Meal *meal = meal_create_with_name("Pizza");
    assert(meal != NULL);
    
    // Using meal_print() instead of accessing meal->name
    printf("Expected output: <some id> Pizza\n");
    printf("Actual output: ");
    meal_print(meal);
    
    printf("test_meal_create_with_name passed if output matches\n");
    meal_destroy(meal);
}

void test_meallist_insert_meal() {
    MealList *list = meallist_create();
    Meal *meal1 = meal_create_with_name("Pizza");
    Meal *meal2 = meal_create_with_name("Burger");

    meallist_insert_meal(list, meal1);
    meallist_insert_meal(list, meal2);

    printf("Expected output:\n<some id> Pizza\n<some id> Burger\n");
    printf("Actual output:\n");
    meallist_print(list);

    printf("test_meallist_insert_meal passed if output matches\n");
    meallist_destroy(list);
}

void test_meallist_remove_meal() {
    MealList *list = meallist_create();
    Meal *meal1 = meal_create_with_name("Pizza");
    Meal *meal2 = meal_create_with_name("Burger");

    meallist_insert_meal(list, meal1);
    meallist_insert_meal(list, meal2);
    meallist_remove_meal(list, 0);  // Remove first meal

    printf("Expected output:\n<some id> Burger\n");
    printf("Actual output:\n");
    meallist_print(list);

    printf("test_meallist_remove_meal passed if output matches\n");
    meallist_destroy(list);
}

void test_meallist_print() {
    MealList *list = meallist_create();
    Meal *meal1 = meal_create_with_name("Pizza");
    meallist_insert_meal(list, meal1);

    printf("Expected output:\n<some id> Pizza\n");
    printf("Actual output:\n");
    meallist_print(list);

    printf("test_meallist_print passed if output matches\n");
    meallist_destroy(list);
}

int main() {
    test_meallist_create();
    test_meal_create_with_name();
    test_meallist_insert_meal();
    test_meallist_remove_meal();
    test_meallist_print();
    printf("All tests passed!\n");
    return 0;
}
