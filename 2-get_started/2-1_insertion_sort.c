#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define LIST_LEN 10

void insertion_sort(int list[], int length) {
    int j;
    int k;
    int i;
    // outer loop start from the second element
    for (j = 1; j < length; j++) {
        k = list[j];
        i = j - 1;
        while (i >= 0 && list[i] > k) {
            list[i+1] = list[i];
            i = i - 1;
        }
        list[i+1] = k;
    }
} 

int main(int argc, char *argv[]) {

    int list[LIST_LEN];
    make_list(list, LIST_LEN);

    // test function pointer
    void (*sort)(int [], int);
    // assign pointer
    sort = insertion_sort;

    // before sorting
    print_list(list, LIST_LEN);

    // perform sorting
    sort(list, LIST_LEN);

    // sorting results
    print_list(list, LIST_LEN);

    return 0;
}
