#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define LIST_LEN 10

void print_list(int list[], int length) {
    printf("length: %d\n", length);
    printf("List: [");
    int counter = 0;
    for (counter; counter < length; counter++) {
        printf("%d, ", list[counter]);
    }
    printf("] \n");
}

int partition(int list[], int low, int high) {

    int x = list[high];
    int i = low - 1;

    int j = 0;
    int tmp = 0;

    printf("low %d, high: %d\n", low, high);
    for (j = low; j < high; j++) {
        printf("this is j %d\n", j);
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
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    int list[LIST_LEN];
    int counter = 0;
    int number = 0;

    // function pointer
    void (*sort)(int [], int, int) = quick_sort;

    for (counter; counter < LIST_LEN; counter++) {
        number = rand() % 1000;
        // use rand() % 1000 will get random number between 1-1000
        list[counter] = number;
    }

    print_list(list, LIST_LEN);

    // use index nubmer
    sort(list, 0, LIST_LEN-1);

    print_list(list, LIST_LEN);

    return 0;
}
