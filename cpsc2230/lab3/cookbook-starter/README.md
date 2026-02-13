# Data Structures Lab: Dynamic ArrayList Implementation

## **Objective**
This lab aims to reinforce your understanding of dynamic memory management, data structures, and procedural programming in C. You will implement a dynamic `ArrayList` structure to store and manage a collection of `Meal` objects. The lab will require you to:

- Create and manage a dynamic array.
- Implement insertion, deletion, and resizing operations.
- Properly allocate and free memory to prevent leaks.
- Develop and execute unit tests for validation.

---

## **Files Overview**
The project consists of the following files:

- `ArrayList.c` / `ArrayList.h` – Implements a dynamic array to store `Meal` objects.
- `Meal.c` / `Meal.h` – Defines a `Meal` structure and associated operations.
- `cookbook.c` – The driver program that reads meal names from a file and stores them in the dynamic list.
- `unittest.c` – Provides unit tests for core functionalities.
- `meal_names.txt` – Contains a list of meal names for testing.
- `Makefile` – Automates the compilation process.

---

## **Tasks to Complete**
Follow the procedural order below to implement missing functionalities.

### **1. Implement the Dynamic ArrayList**
- **File:** `ArrayList.c`
- **Functions to complete:**
  1. **`meallist_create()`**: 
     - Allocate memory for a `MealList` struct.
     - Initialize the variables.
     - Allocate an initial array of pointers for meals (size `INITIAL_CAPACITY`).
  2. **`meallist_insert_meal(MealList *list, Meal *m)`**:
     - Check if the list is full; if so, expand it.
     - Insert the new meal at the end.
  3. **`expand_meallist(MealList *list)`**:
     - Double the capacity.
     - Reallocate memory for the expanded array.

### **2. Implement Memory Deallocation**
- **File:** `ArrayList.c`
- **Functions to complete:**
  1. **`meallist_destroy(MealList *list)`**:
     - Free each `Meal` stored in the list.
     - Free the array of pointers.
     - Free the `MealList` struct itself.

### **3. Implement Meal Removal**
- **File:** `ArrayList.c`
- **Functions to complete:**
  1. **`meallist_remove_meal(MealList *list, int index)`**:
     - Remove a meal from the list.
     - Shift remaining meals.
     - Shrink capacity if necessary.
  2. **`shrink_meallist(MealList *list)`**
     - Reduce the capacity when the list size decreases significantly.

### **4. Test Your Implementation**
- **File:** `unittest.c`
- **Run unit tests to verify functionality.**
  ```sh
  make test
  ./unittest
