#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"

#define LIST_LEN 8

void merge1(int list[], int start, int mid, int end) {
    int L[20];
    int R[20];
    int c;
    // length of first half
    int n1 = mid - start + 1;
    // length of second half
    // mid will be in the first half
    int n2 = end - mid;

    for (c = 0; c < n1; c++) {
        L[c] = list[start+c];
    }
    // make the loop at the end working
    L[n1] = 9999;

    for (c = 0; c < n2; c++) {
        R[c] = list[mid+c+1];
    }
    R[n2] = 9999;

    int i = 0;
    int j = 0;
    int k;

    for (k = start; k <= end; k++) {
        if (L[i] <= R[j]) {
            list[k] = L[i];
            i++;
        } else {
            list[k] = R[j];
            j++;
        }
    }
}

// alternative merge algorithm
void merge2(int list[], int start, int mid, int end) {
    int temp[20];
    int i, j, k;
    i = 0;
    j = start;
    while (j<=mid) {
        temp[i++] = list[j++];
    }
    i = 0;
    k = start;
    while (k<j && j<=end) {
        if (temp[i]<=list[j]) {
            list[k++] = temp[i++];
        } else {
            list[k++] = list[j++];
        }
    }

    while (k<j) {
        list[k++] = temp[i++];
    }
}

void merge_sort(int list[], int start, int end) {
    int mid;
    if (start < end) {
        // length is start+end+1
        mid = (int)((start+end)/2);
        merge_sort(list, start, mid);
        merge_sort(list, mid+1, end);
        merge1(list, start, mid, end);
    }
}

int main(int argc, char *argv[]) {
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed);

    int list[LIST_LEN];
    int counter;
    int number = 0;

    // test function pointer
    void (*sort)(int [], int, int) = merge_sort;

    for (counter = 0; counter < LIST_LEN; counter++) {
        number = rand() % 1000;
        // use rand() % 1000 will get random number between 1-1000
        list[counter] = number;
    }

    print_list(list, LIST_LEN);

    sort(list, 0, LIST_LEN-1);

    print_list(list, LIST_LEN);

    return 0;
}
