/*
* File: linked_list.h
* Author: Ozan Erat
* Date: 2/13/2025
* Description: Interface for a singly linked list for the Linked_list lab.
* 
*/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>

/**
 * Opaque type definition for a linked list.
 * We hide the internal Node structure from users of the interface.
 */
typedef struct list_instance_t LinkedList;

/** 
 * Creates and returns a new empty LinkedList.
 * Returns NULL on allocation failure.
 */
LinkedList *list_create();

/**
 * Frees all nodes in the given linked list and their associated data,
 * then frees the LinkedList struct itself.
 * Passing NULL is safe (no operation).
 */
void list_destroy(LinkedList *list);

/**
 * Reads lines from the given file handle and creates a linked list,
 * where each line is stored as a separate string in a node.
 * Returns the created list on success, or NULL on failure.
 */
LinkedList *read_list_from_file(FILE *file);

/**
 * Zips list_b into list_a by alternating nodes.
 * Modifies list_a in place, returning the same pointer as list_a.
 * If list_b is NULL or list_a is NULL, returns NULL.
 */
LinkedList *zip_list(LinkedList *list_a, LinkedList *list_b);

/**
 * Reverses the given linked list in place.
 * Returns the same pointer to the list (for convenience).
 */
LinkedList *reverse_list(LinkedList *list);

/**
 * Prints each song in the linked list on its own line to the specified stream.
 * No trailing spaces or extra formatting.
 */
void print_list(const LinkedList *list, FILE *stream);

#endif // LINKED_LIST_H
