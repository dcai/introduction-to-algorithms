#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void insertion_sort(int list[], int length) {
    int j = 1;
    int k;
    int i;
    for (j; j < length; j++) {
        k = list[j];
        i = j - 1;
        while (i >= 0 && list[i] > k) {
            list[i+1] = list[i];
            i = i - 1;
        }
        list[i+1] = k;
    }
    print_list(list, length);
} 

int main(int argc, char *argv[]) {
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    int list[LIST_LEN];
    int counter = 0;
    int number = 0;

    // test function pointer
    void (*sort)(int [], int);
    // assign pointer
    sort = insertion_sort;

    for (counter; counter < LIST_LEN; counter++) {
        number = rand() % 1000;
        // use rand() % 1000 will get random number between 1-1000
        list[counter] = number;
    }
    print_list(list, LIST_LEN);

    sort(list, LIST_LEN);

    /*printf("length: %ld\n", sizeof(list)/sizeof(2));*/

    return 0;
}
