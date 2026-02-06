#include <stdio.h>
#include <string.h> 
#include "PirateList.h"

// Initialize the list
void piratelist_init(List *list) {
    list->length = 0;
    // list->pirates[MAX_PIRATES];
}


// Read all lines from file and add to list. 
int piratelist_add(List *list, FILE *file) {

if (list->length >= MAX_PIRATES) {
        return 0; 
    }

    char line[LINE_MAX];
    // Read each line from the file with fgets preferably
    // create a Pirate struct for each line and copy it
    // add it to the list if there is space, use return 0 if full
    Pirate pir; 

    // FILE *names = fopen(file, "r");

    int i = 0;
    

while (list->length < MAX_PIRATES && fgets(line, LINE_MAX, file) != NULL) {
        pir.pirate_id=i+1;
        strcpy (pir.name, line);
        list->pirates[list->length] = pir;
        list->length ++;
        i++;
    }

    // fclose(file);

    if (MAX_PIRATES - list->length < 1) {
        return 0;
    } else {
        return 1;
    }

    // return 1;
    

}

// Print the whole list
void piratelist_print(const List *list) {
    for (int i = 0; i < list->length; i++) {
        // print each pirate in the list
        // use the pirate_id and name fields

        printf("%i", list->pirates[i].pirate_id);
        printf(" ; ");
        printf(list->pirates[i].name);
    }
    printf("\n");
}
