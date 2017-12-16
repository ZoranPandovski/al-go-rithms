#include <stdio.h>
#include <stdlib.h>


/*
 * returns the index of the maximum element in ar
 */
int ternary_search(int array[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int mid1 = start + (end - start) / 3;
        int mid2 = end - (end - start) / 3;
        if (array[mid1] <= array[mid2]) {
            start = mid1 + 1;
        } else {
            end = mid2 - 1;
        }
    }
    return start;
}

int main() {
    freopen("tests.txt", "r", stdin);
    int num_tests;
    scanf("%d",&num_tests);

    for (int t = 0; t < num_tests; t++){
        int n;
        scanf("%d",&n);
        int array[n];
        for (int i = 0; i < n; i++){
            scanf("%d",&array[i]);
        }
        printf("Test# %d : %d \n",t+1,array[ternary_search(array, n)]);
    }
    return 0;
}

