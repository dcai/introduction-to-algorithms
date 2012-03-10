#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "common.h"

#define LIST_LEN 10

int parent(int i) {
    /*return (int)floor(i/2);*/
    // divide is right shift
    return i >> 1;
}

int left(int i) {
    // 2 * i
    return (i << 1) + 1;
}

int right(int i) {
    // 2 * i + 1
    return (i << 1) + 2;
}

void max_heapify(int list[], int i, int heap_size) {
    int l = left(i);
    int r = right(i);
    int largest;
    int temp;

    if ((l < heap_size) && (list[l] > list[i])) {
        largest = l;
    } else {
        largest = i;
    }

    if ((r < heap_size) && (list[r] > list[largest])) {
        largest = r;
    }

    if (largest != i) {
        temp = list[i];
        list[i] = list[largest];
        list[largest] = temp;
        max_heapify(list, largest, heap_size);
    }
    
}

void build_max_heap(int list[], int length) {
    int i;
    for (i = (length-1)/2; i >=0; i--) {
        max_heapify(list, i, length);
    }
}

void heap_sort(int list[], int length) {
    build_max_heap(list, length);

    int temp;
    int i;

    for (i = length - 1; i > 0; i--) {
        temp = list[0];
        list[0] = list[i];
        list[i] = temp;
        max_heapify(list, 0, i);
    }
}

int main(int argc, char *argv[]) {
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    int list[LIST_LEN];
    int counter;
    int number = 0;

    // test function pointer
    void (*sort)(int [], int) = heap_sort;

    for (counter = 0; counter < LIST_LEN; counter++) {
        number = rand() % 1000;
        // use rand() % 1000 will get random number between 1-1000
        list[counter] = number;
    }
    /*printf("parent of %d is %d\n", 7, parent(7));*/
    /*printf("left of %d is %d\n", 7, left(7));*/
    /*printf("right of %d is %d\n", 7, right(7));*/

    print_list(list, LIST_LEN);

    sort(list, LIST_LEN);

    print_list(list, LIST_LEN);

    return 0;
}
