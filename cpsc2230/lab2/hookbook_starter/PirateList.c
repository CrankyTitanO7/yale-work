#include <stdio.h>
#include <string.h> 
#include "PirateList.h"

// Initialize the list
void piratelist_init(List *list) {
    list->length = MAX_PIRATES;
    // list->pirates[MAX_PIRATES];
}


// Read all lines from file and add to list. 
int piratelist_add(List *list, FILE *file) {
    char line[LINE_MAX];
    // Read each line from the file with fgets preferably
    // create a Pirate struct for each line and copy it
    // add it to the list if there is space, use return 0 if full
    Pirate pir; 

    FILE *names = fopen(* (file), "r");

    int i = 0;

    while (line[i] != EOF && MAX_PIRATES - list->length < 1){
        fgets(line, LINE_MAX, pir.name);
        pir.pirate_id=i;
        list->pirates[list->length] = pir;
        list->length ++;
        i++;

        
    }

    fclose(names);

    if (MAX_PIRATES - list->length < 1) {
        return 0;
    } else {
        return 1;
    }
    

}

// Print the whole list
void piratelist_print(const List *list) {
    for (int i = 0; i < list->length; i++) {
        // print each pirate in the list
        // use the pirate_id and name fields
    }
    printf("\n");
}
