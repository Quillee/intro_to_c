#include "all.h"

void swap_val(int *i, int *j) {
   int t = *i;
   *i = *j;
   *j = t;
}

void insertion_sort(int a[], int n) {
    int i, j;

    for(i = 0; i < n; i++) {
        j=i;
        while(j > 0 && (a[j] < a[j-1])) {
            swap_val(&a[j], &a[j-1]);
            j = j - 1;
        }
    }
}
