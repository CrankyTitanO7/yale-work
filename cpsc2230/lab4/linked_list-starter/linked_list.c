/*
* File: linked_list.c
* Author: Ozan Erat
* Date: 2/13/2025
* Description: Implementation of a singly linked list for the Linked_list lab.
* 
*/
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Node struct: holds a `song` string and a pointer to the next node.
 */
typedef struct Node {
    char *song;         // String content for this node
    struct Node *next;  // Pointer to next node
} Node;

/**
 * The LinkedList struct holds pointers to the head and tail of the list.
 */
struct list_instance_t {
    Node *head; // Points to the first node in the list
    Node *tail; // Points to the last node in the list 
};

/**
 * Prints the content of each node in the list to the specified output stream,
 * each on its own line. If list is NULL, does nothing.
 */
void print_list(const LinkedList *list, FILE *stream) {
    if (!list) return;
    
    Node *current = list->head;
    while (current) {
        fprintf(stream, "%s\n", current->song);
        current = current->next;
    }
}
/**
 * Allocates and returns a new, empty LinkedList struct.
 * head and tail are initialized to NULL.
 * Returns NULL if allocation fails.
 */
LinkedList *list_create() {
    LinkedList *list = malloc(sizeof(LinkedList));
    if (!list) {
        fprintf(stderr, "Memory allocation failed for LinkedList\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

/**
 * Reads lines from a file and stores them in a newly allocated linked list.
 * Each line becomes a dynamically allocated string in a new node.
 * Returns the list on success, or NULL on failure.
 */
LinkedList *read_list_from_file(FILE *file) {
    // Create an empty list
    LinkedList *list = list_create();
    if (!list) return NULL;
    
    char line[256];  // Buffer to store each line temporarily
    
    // Read line by line
    while (fgets(line, sizeof(line), file)) {
        // Remove trailing newline
        line[strcspn(line, "\n")] = '\0';
        
        // Allocate a new node
        Node *new_node = malloc(sizeof(Node));
        if (!new_node) {
            fprintf(stderr, "Memory allocation failed for a node\n");
            list_destroy(list);
            return NULL;
        }
        // Duplicate the string read into the new node's 'song'
        // Allocate memory for the song string and copy the contents
        new_node->song = malloc(strlen(line) + 1);
        if (!new_node->song) {
            fprintf(stderr, "Memory allocation failed for song string\n");
            free(new_node);
            list_destroy(list);
            return NULL;
        }
        strcpy(new_node->song, line);
        new_node->next = NULL;
        
        // Append node to list
        if (!list->head) {
            // If the list is empty
            list->head = new_node;
        } else {
            // If the list is not empty, link the tail to the new node
            list->tail->next = new_node;
        }
        // Update the tail pointer to the new node
        list->tail = new_node;
    }
    return list;
}

/**
 * zip_list(list_a, list_b):
 *    Inserts the nodes of list_b into list_a:
 *    a1 -> b1 -> a2 -> b2 -> ...
 *    This is done "in place" by modifying the 'next' pointers of the existing nodes.
 * 
 *    - list_a is returned as the merged list.
 *    - If list_a is empty, list_b's nodes become list_a's.
 *    - If list_b is empty, list_a is unchanged.
 *    - If either pointer is NULL, returns NULL (error).
 */
LinkedList *zip_list(LinkedList *list_a, LinkedList *list_b) {
    // Check for invalid input
    if (!list_a || !list_b) return NULL;
    
    Node *current1 = list_a->head;
    Node *current2 = list_b->head;
    Node *next1, *next2;
    
    // TODO: Traverse both lists and insert nodes from list_b into list_a

    while (current1->next != NULL || current2->next != NULL){
        next1 = current1->next;
        next2 = current2->next;

        current1->next = current2;
        current2->next = next1;
        // next1->next  = next2;

        current1 = next1;
        current2 = next2;
        // printf("%p\n", current1->next);
    }

    // TODO: Handle the edge case where one list is shorter than the other. 
        // If we finished list_a but still have nodes in list_b,
        // just attach the remainder of list_b to the end of list_a.
    // Your function would still work for current input file even though you don't handle this edge case. However, some test will fail if you don't handle this edge case on Gradescope. It is a good practice to handle edge cases.
    
    current1->next = current2; 
    // no matter what, current2 needs to be after the last element of current1. 
    // the case "if current2->next != NULL" is inherently fixed

    // Return the pointer to list_a, which now represents the merged list
    // list_destroy(list_b);
    return list_a;
}

/**
 * Reverses the linked list in place by iterating and flipping next pointers.
 * Updates both head and tail accordingly. Returns the same list pointer.
 */
LinkedList *reverse_list(LinkedList *list) {
    if (!list) return NULL;

    Node *prev = NULL;
    Node *current = list->head;
    Node *next = NULL;

    Node *head = current;
    
    
    // TODO (OPTIONAL): Traverse the list with a while loop and reverse the pointers
    while (current->next != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // TODO (OPTIONAL): Reassign the tail (the new tail is the old head)
    list->head = current;
    current->next = prev;
    list->tail = head;
    
    
    return list;
}

/**
 * Frees all nodes and strings contained in the list, then frees the list struct.
 * If `list` is NULL, does nothing.
 */
void list_destroy(LinkedList *list) {
    // TODO: Check for NULL list

    
    Node *current = list->head; // Start from the headT
    Node *next;
    while (current) {
        // TODO: Traverse the list 
        next = current->next;
        // TODO: Free the string in the Node (strdup was used to allocate on heap)
        free(current->song);
        // TODO: Free the Node itself
        free(current);
        current = next;
    }
    // TODO: Finally free the LinkedList struct
    free(list);
}
