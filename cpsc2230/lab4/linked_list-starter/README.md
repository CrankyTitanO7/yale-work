# Linked List Lab

## Overview

In this lab, you will complete the implementation of a singly linked list in C by filling in the missing functionality. 

You are given starter code in `linked_list.c`, with `TODO` comments marking the sections you need to complete.

The program will **read songs from files**, create a **playlist**, and allow them to be **shuffled in reverse order**.

## Learning Goals

By completing this lab, you will:
- Understand how strings are read from a file and stored in a linked list.
- Implement the `zip_list` function to merge two lists in an alternating pattern.
- Implement `list_destroy` to correctly free all allocated memory.
- (Optional) Implement `reverse_list` to reverse a linked list in place.

## Task 1: Understand `read_list_from_file` (No Changes Required)

### Objective
Before writing any code, first understand how `read_list_from_file` works. This function is **already implemented**, 
and you do **not** need to modify it.

### Key Concepts
- The function **reads lines from a file** into a `char line[256]` buffer.
- It **removes the newline** character at the end of each line.
- It **allocates a new node** and assigns the string to `new_node->song` using `strdup`.
- The function **uses `strdup`** to create a **new copy** of the string.
- It **appends nodes to the tail** of the list.

### What You Need to Do
- **Read the function carefully** in `linked_list.c`.
- **Make sure you understand why `strdup` is necessary** before proceeding.

---

## Task 2: Implement `zip_list`

### Objective
Complete the `zip_list` function so that it merges `list_b` into `list_a` in an alternating pattern.

### Expected Behavior
If `list_a` and `list_b` are:

```
list_a: A1 → A2 → A3
list_b: B1 → B2 → B3
```

After calling `zip_list(list_a, list_b)`, the result should be:

```
A1 → B1 → A2 → B2 → A3 → B3
```

### Steps to Implement
1. Locate `zip_list` in `linked_list.c`.
2. Use **two pointers**, `current1` and `current2`, to **traverse** both lists.
3. Update the `next` pointers **to interleave nodes** from `list_b` into `list_a`.
4. **(Optional)** Handle the edge case where one list is **shorter** than the other.

📌 **Once implemented, `zip_list` should return `list_a`, now containing all nodes.**

---

## Task 3: Implement `list_destroy`

### Objective
Ensure that **all dynamically allocated memory** is properly freed when the linked list is no longer needed.

### Steps to Implement
1. Locate `list_destroy` in `linked_list.c`.
2. If `list` is `NULL`, do nothing.
3. Start from `list->head` and **traverse the list**.
4. For each node:
   - **Free the `song` string** (since `strdup` allocated it on the heap).
   - **Free the node itself**.
5. Finally, **free the `LinkedList` struct**.

✅ **After implementing this function, running `list_destroy` should correctly clean up all allocated memory.**

---

## Optional Task 4: Implement `reverse_list`

### Objective
Modify `reverse_list` to **reverse the order of nodes** in the linked list.

### Expected Behavior
If the original list is:

```
A → B → C → D
```

After calling `reverse_list(list)`, the new order should be:

```
D → C → B → A
```

### Steps to Implement
1. Use **three pointers**: `prev`, `current`, and `next`.
2. Traverse the list, flipping `next` pointers **so they point backward**.
3. Update `list->head` to the **new first node** (which was the original last node).
4. Update `list->tail` to the **new last node**.

🚨 **This task is optional. You will not lose points if you skip it.**

---

## Summary of What You Need to Do

| Task | Description | Required? |
|------|------------|-----------|
| **Understand `read_list_from_file`** | Read and understand how it works | ✅ Yes |
| **Implement `zip_list`** | Merge `list_b` into `list_a` in alternating order | ✅ Yes |
| **(Optional) Handle shorter list case in `zip_list`** | If one list is shorter, attach remaining nodes | ❌ No (Optional) |
| **Implement `list_destroy`** | Free all allocated memory | ✅ Yes |
| **(Optional) Implement `reverse_list`** | Reverse the linked list in place | ❌ No (Optional) |

---

## How to Run Your Code

### 1️⃣ **Compile Your Code**
Run the following command to compile:

gcc -Wall -Wextra -g -o main main.c linked_list.c

or simply run `make`

### 2️⃣ **Run the Program**
After compilation, run:

./main
 
 or simply run `make run`

### 3️⃣ **Check for Memory Leaks**
To make sure all allocated memory is freed correctly, run:

valgrind --leak-check=full ./main

or simply run `valgrind valgrind`

If `list_destroy` is implemented correctly, Valgrind should report **no memory leaks**.

---

## Submission Instructions

1. Ensure **`zip_list` and `list_destroy` are fully implemented**.
2. **(Optional)** If you completed `reverse_list` or handled the shorter list case in `zip_list`, add a comment in your code explaining how you handled it.
3. Submit everything to **gradescope** 

🚀 **Good luck! Happy coding!**
