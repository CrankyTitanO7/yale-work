/*
* File: main.c
* Author: Ozan Erat
* Date: 2/13/2025
* Description: Main function for the Linked_list lab. 
* 
*/
#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Main function that:
 *   1. Opens two input files.
 *   2. Reads two linked lists (list_a and list_b) from those files.
 *   3. Zips list_b into list_a in-place (so they share one list).
 *   4. Reverses the merged list.
 *   5. Prints both the zipped list and then the reversed list.
 *   6. Frees resources properly.
 */
int main() {
    // Attempt to open input files
    FILE *fa = fopen("song_list_a.in", "r");
    FILE *fb = fopen("song_list_b.in", "r");
    if (!fa || !fb) {
        fprintf(stderr, "Error opening input files\n");
        if (fa) fclose(fa);
        if (fb) fclose(fb);
        return EXIT_FAILURE;
    }

    // Read data from files into two separate linked lists
    LinkedList *list_a = read_list_from_file(fa);
    LinkedList *list_b = read_list_from_file(fb);

    // Close file handles after reading
    fclose(fa);
    fclose(fb);

    // Check if either list allocation or reading failed
    if (!list_a || !list_b) {
        fprintf(stderr, "Error creating lists from files\n");
        // Destroy whichever lists were allocated to avoid leaks
        if (list_a) list_destroy(list_a);
        if (list_b) list_destroy(list_b);
        return EXIT_FAILURE;
    }

    // Merge list_b into list_a (zipping them together)
    // NOTE: This operation modifies list_a in place!
    LinkedList *zipped_list = zip_list(list_a, list_b);
    if (!zipped_list) {
        fprintf(stderr, "Error zipping lists\n");
        // Clean up both lists
        list_destroy(list_a);
        list_destroy(list_b);
        return EXIT_FAILURE;
    }

    // Print the merged (zipped) list
    printf("\nZipped List:\n");
    print_list(zipped_list, stdout);

    // Reverse the merged list in place
    LinkedList *reversed_list = reverse_list(zipped_list);
    printf("Reversed List:");
    print_list(reversed_list, stdout);

    // At this point:
    //   zipped_list == list_a == reversed_list (all are the same merged list).

    // Destroy the final merged list (only one destroy call, to avoid double-free).
    list_destroy(reversed_list);

    // We've taken all the nodes from list_b and spliced them into list_a.
    // So list_b->head and list_b->tail no longer point to valid separate data.
    // We can safely free just the LinkedList struct of list_b.
    free(list_b);

    return 0;
}
