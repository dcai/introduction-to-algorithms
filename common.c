#include "common.h"
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
