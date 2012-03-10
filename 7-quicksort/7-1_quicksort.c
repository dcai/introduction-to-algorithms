#include <stdio.h>
#include <stdlib.h>
#include "common.h"

#define LIST_LEN 10

int partition(int list[], int low, int high) {

    int x = list[high];
    int i = low - 1;

    int j = 0;
    int tmp = 0;

    for (j = low; j < high; j++) {
        if (list[j] <= x) {
            i++;
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
        }
    }
    tmp = list[i+1];
    list[i+1] = list[high];
    list[high] = tmp;
    return i+1;
}

void quick_sort(int list[], int low, int high) {
    if (low < high) {
        int q = partition(list, low, high);
        quick_sort(list, low, q - 1);
        quick_sort(list, q + 1, high);
    }
}

int main(int argc, char *argv[]) {

    int list[LIST_LEN];
    make_list(list, LIST_LEN);

    // function pointer
    void (*sort)(int [], int, int) = quick_sort;

    print_list(list, LIST_LEN);

    // use index nubmer
    sort(list, 0, LIST_LEN-1);

    print_list(list, LIST_LEN);

    return 0;
}
