
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

/* 
 * Internal Node structure from linked_list.c for convenience.
 * We don't need the details in a normal user context, but for 
 * thorough testing (like comparing results), we might replicate them.
 * 
 * If you want to truly treat LinkedList as opaque, you'd rely on
 * public functions to validate results (like printing and checking output).
 * For demonstration, we'll replicate minimal details here to walk the list.
 */
typedef struct Node {
    char *song;
    struct Node *next;
} Node;


struct LinkedList {
    Node *head;
    Node *tail;
};
 

/* 
 * Helper function: compare_list_to_array
 * Compares the contents of a LinkedList to a NULL-terminated string array.
 * Returns 1 if they match exactly (same length & contents), otherwise 0.
 */
 int compare_list_to_array(const LinkedList *list, const char *arr[]) {
    if (!list && !arr) return 1;  // both NULL => "match"
    if (!list || !arr) return 0;  // mismatch if one is NULL but not the other

    Node *current = ((struct LinkedList*)list)->head;
    int index = 0;
    while (current && arr[index]) {
        if (strcmp(current->song, arr[index]) != 0) {
            return 0; // found a mismatch
        }
        current = current->next;
        index++;
    }

    // Both should end together
    if (current == NULL && arr[index] == NULL) {
        return 1;  // perfect match
    }
    return 0;  // length mismatch
}

/*
 * Helper function: create_list_from_array
 * Builds a new LinkedList from a NULL-terminated array of strings.
 * Returns the new list pointer. 
 * If memory fails at any point, it returns NULL.
 */
LinkedList* create_list_from_array(const char *arr[]) {
    LinkedList *list = list_create();
    if (!list) return NULL;
    
    for (int i = 0; arr[i] != NULL; i++) {
        Node *new_node = malloc(sizeof(Node));
        if (!new_node) {
            // Clean up everything allocated so far
            list_destroy(list);
            return NULL;
        }
        new_node->song = strdup(arr[i]);
        if (!new_node->song) {
            free(new_node);
            list_destroy(list);
            return NULL;
        }
        new_node->next = NULL;

        // Append to the list
        if (((struct LinkedList*)list)->head == NULL) {
            ((struct LinkedList*)list)->head = new_node;
        } else {
            ((struct LinkedList*)list)->tail->next = new_node;
        }
        ((struct LinkedList*)list)->tail = new_node;
    }

    return list;
}

/*
 * Format requirement function:
 *   - Prints "PASSED\t<test_name>" or "FAILED\t<test_name>"
 *   - Then can print 0 or more lines each starting with 6 spaces + a tab,
 *     providing additional context about the test result.
 */
 void print_test_result(int passed, const char *test_name, const char *additional_info) {
    if (passed) {
        printf("PASSED\t%s\n", test_name);
    } else {
        printf("FAILED\t%s\n", test_name);
    }

    /* If additional context is provided, print it. 
       Each line must start with 6 spaces and then a tab. */
    if (additional_info && *additional_info) {
        /* 
         * additional_info could have multiple lines if you want them.
         * For example, you might parse the string for '\n' and print each line separately. 
         * For simplicity, here's a single line example. 
         */
        printf("      \t%s\n", additional_info);
    }
}

/*
 * Test #1: zip_list when both lists have the same length.
 */
 void test_zip_same_length() {
    const char *arrA[] = {"A1", "A2", "A3", NULL};
    const char *arrB[] = {"B1", "B2", "B3", NULL};
    const char *expected[] = {"A1", "B1", "A2", "B2", "A3", "B3", NULL};

    LinkedList *list_a = create_list_from_array(arrA);
    LinkedList *list_b = create_list_from_array(arrB);

    zip_list(list_a, list_b);  // modifies list_a in place
    int pass = compare_list_to_array(list_a, expected);

    if (pass) {
        // Perfect
        print_test_result(1, "test_zip_same_length", NULL);
    } else {
        // Show details
        print_test_result(0, "test_zip_same_length", "Zipping 3 elements from each did not match expected order.");
        // Freed only the merged list once:
    }

    list_destroy(list_a);
    free(list_b);
}

/*
 * Test #2: zip_list when list_a is shorter than list_b.
 * list_a = {A1, A2}, list_b = {B1, B2, B3, B4}
 * Expected = {A1, B1, A2, B2, B3, B4}
 */
 void test_zip_a_shorter_than_b() {
    const char *arrA[] = {"A1", "A2", NULL}; 
    const char *arrB[] = {"B1", "B2", "B3", "B4", NULL};  
    const char *expected[] = {"A1", "B1", "A2", "B2", "B3", "B4", NULL};

    LinkedList *list_a = create_list_from_array(arrA);
    LinkedList *list_b = create_list_from_array(arrB);

    zip_list(list_a, list_b);

    int result = compare_list_to_array(list_a, expected);
    
    // Debugging Output if test fails
    if (!result) {
        printf("FAILED\ttest_zip_a_shorter_than_b\n");
        printf("      \tExpected:\n");
        for (int i = 0; expected[i] != NULL; i++) {
            printf("      \t\t%s\n", expected[i]);
        }
        printf("      \tGot:\n");
        print_list(list_a, stdout);
    } else {
        printf("PASSED\ttest_zip_a_shorter_than_b\n");
    }

    list_destroy(list_a);
    free(list_b);
}


/*
 * Test #3: zip_list when list_a is empty and list_b has data.
 * list_a = {}, list_b = {B1, B2, B3}
 * Expected = {B1, B2, B3}
 */
 void test_zip_a_empty() {
    const char *arrA[] = {NULL}; 
    const char *arrB[] = {"B1", "B2", "B3", NULL};
    const char *expected[] = {"B1", "B2", "B3", NULL};

    LinkedList *list_a = create_list_from_array(arrA);
    LinkedList *list_b = create_list_from_array(arrB);

    zip_list(list_a, list_b);
    int pass = compare_list_to_array(list_a, expected);

    if (pass) {
        print_test_result(1, "test_zip_a_empty", NULL);
    } else {
        print_test_result(0, "test_zip_a_empty", "Empty list_a did not end up as list_b's contents");
    }

    list_destroy(list_a);
    free(list_b);
}

/*
 * Test #4: reverse_list with multiple elements 
 * arr = {Song1, Song2, Song3}, expected reversed = {Song3, Song2, Song1}
 */
 void test_reverse_multiple() {
    const char *arr[] = {"Song1", "Song2", "Song3", NULL};
    const char *expected[] = {"Song3", "Song2", "Song1", NULL};

    LinkedList *list = create_list_from_array(arr);

    reverse_list(list);
    int pass = compare_list_to_array(list, expected);

    if (pass) {
        print_test_result(1, "test_reverse_multiple", NULL);
    } else {
        print_test_result(0, "test_reverse_multiple", "Reverse of 3 elements did not match expected order");
    }

    list_destroy(list);
}

/*
 * Test #5: reverse_list with a single element 
 * Expected to remain the same
 */
 void test_reverse_single() {
    const char *arr[] = {"OnlyOne", NULL};
    const char *expected[] = {"OnlyOne", NULL};

    LinkedList *list = create_list_from_array(arr);

    reverse_list(list);
    int pass = compare_list_to_array(list, expected);

    if (pass) {
        print_test_result(1, "test_reverse_single", NULL);
    } else {
        print_test_result(0, "test_reverse_single", "Single-element list changed incorrectly after reverse");
    }

    list_destroy(list);
}

/*
 * Test #6: reverse_list on an empty list
 * Should remain empty (head/tail = NULL)
 */
 void test_reverse_empty() {
    const char *arr[] = {NULL}; // empty
    LinkedList *list = create_list_from_array(arr);

    reverse_list(list);
    // list should still be empty
    int is_empty = (((struct LinkedList*)list)->head == NULL && 
                    ((struct LinkedList*)list)->tail == NULL);

    if (is_empty) {
        print_test_result(1, "test_reverse_empty", NULL);
    } else {
        print_test_result(0, "test_reverse_empty", "Empty list was not recognized as empty after reverse");
    }

    list_destroy(list);
}
/** 
 * Test zip_list when list_b is shorter than list_a 
 */
 void test_zip_b_shorter_than_a() {
    const char *arrA[] = {"A1", "A2", "A3", "A4", NULL}; 
    const char *arrB[] = {"B1", "B2", NULL};  
    const char *expected[] = {"A1", "B1", "A2", "B2", "A3", "A4", NULL};

    LinkedList *list_a = create_list_from_array(arrA);
    LinkedList *list_b = create_list_from_array(arrB);

    zip_list(list_a, list_b);

    int result = compare_list_to_array(list_a, expected);

    if (!result) {
        printf("FAILED\ttest_zip_b_shorter_than_a\n");
        printf("      \tExpected:\n");
        for (int i = 0; expected[i] != NULL; i++) {
            printf("      \t\t%s\n", expected[i]);
        }
        printf("      \tGot:\n");
        print_list(list_a, stdout);
    } else {
        printf("PASSED\ttest_zip_b_shorter_than_a\n");
    }

    list_destroy(list_a);
    free(list_b);
}

/* 
 * main: runs all tests in sequence 
 * Lines not starting with "PASSED\t" or "FAILED\t" are 
 * ignored by the autograder, but can show up for local debugging.
 */
int main(void) {
    printf("\n");

    test_zip_same_length();
    printf("2 lists of same length\n");
    test_zip_a_shorter_than_b();
    printf("a shorter than b\n");
    test_zip_b_shorter_than_a();
    printf("b shorter than a\n");
    test_zip_a_empty();
    printf("hehe a is empty :3\n");

    test_reverse_multiple();
    printf("reverse list with multiple elements\n");
    test_reverse_single();
    printf("reverse list with single element\n");
    test_reverse_empty();
    printf("reverse list that is empty\n");

    printf("\nAll tests finished.\n");
    return 0;
}
