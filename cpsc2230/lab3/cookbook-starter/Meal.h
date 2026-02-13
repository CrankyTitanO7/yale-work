/*
* File Name: Meal.h
* Author: Ozan Erat
* Date: 2/6/2025
* Version: 1.0.
* Description: 
*   Interface of Meal for the Cookbook lab
*/
#ifndef MEAL_H
#define MEAL_H

#include <stdbool.h>
#include <stdio.h>

// Forward declaration for opaque Meal struct
typedef struct meal_instance_t Meal;

// Function prototypes

Meal* meal_create_with_name(const char *name);
void meal_destroy(Meal *m);
void meal_print(const Meal *m);
void meal_assign_id(Meal *m);

#endif
