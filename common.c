#include "common.h"
#include <time.h>
#include <math.h>
#include <stdlib.h>
/**
 * Print all elements in list
 */
void print_list(int list[], int length) {
    printf("List: [");
    int counter;
    for (counter = 0; counter < length; counter++) {
        if (counter == length - 1) {
            printf("%d", list[counter]);
        } else {
            printf("%d, ", list[counter]);
        }
    }
    printf("] \n");
}

void make_list(int list[], int length) {
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    int counter;

    for (counter = 0; counter < length; counter++) {
        // use rand() % 1000 will get random number between 1-1000
        list[counter] = rand() % 1000;
    }
}
