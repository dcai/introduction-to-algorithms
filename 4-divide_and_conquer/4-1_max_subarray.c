#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIST_LEN 16

typedef struct {
    int low;
    int high;
    int sum;
} section;

void print_section(section sec) {
    printf("low: %d, high: %d, sum: %d\n", sec.low, sec.high, sec.sum);
}

void print_list(int list[], int length) {
    printf("List: [");
    int counter = 0;
    for (counter; counter < length; counter++) {
        printf("%d, ", list[counter]);
    }
    printf("] \n");
}

section find_max_cross_subarray(int list[], int low, int mid, int high) {
    int left_sum = -999;
    int right_sum = -999;
    int max_left = 0;
    int max_right = 0;
    int sum = 0;
    int i;
    for (i=mid; i>=low; i--) {
        sum += list[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for (i=mid+1; i <= high; i++) {
        sum += list[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    section ret = {max_left, max_right, left_sum+right_sum};
    return ret;
} 

section find_max_subarray(int list[], int low, int high) {
    if (low == high) {
        section el = {low, high, list[low]};
        return el;
    } else {
        int mid = (low+high) / 2;
        section left = find_max_subarray(list, low, mid);
        section right = find_max_subarray(list, mid+1, high);
        section cross = find_max_cross_subarray(list, low, mid, high);
        if (left.sum >= right.sum && left.sum >= cross.sum) {
            section ret = {left.low, left.high, left.sum};
            return ret;
        } else if (right.sum >= left.sum && right.sum >= cross.sum) {
            section ret = {right.low, right.high, right.sum};
            return ret;
        } else {
            section ret = {cross.low, cross.high, cross.sum};
            return ret;
        }
    }
}

int main(int argc, char *argv[]) {
    int list[LIST_LEN] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    section result = find_max_subarray(list, 0, LIST_LEN - 1);
    print_section(result);
    print_list(list, LIST_LEN);

    return 0;
}