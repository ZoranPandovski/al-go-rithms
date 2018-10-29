#include "stdio.h"
#include <omp.h>

void merge(int a[], int l, int m, int r){
    int temp1[m - l +1], temp2[r - m];
    for(int i = 0; i < (m-l+1); i++){
        temp1[i] = a[l + i];
    }
    for(int i = 0; i < (r-m); i++){
        temp2[i] = a[m + i +1];
    }
    int i = 0, j = 0, k = l;
    while(i < (m-l+1) && j < (r-m)){
        if(temp1[i] > temp2[j]){
            a[k++] = temp2[j++];
        }
        if(temp1[i] < temp2[j]){
            a[k++] = temp1[i++];
        }
    }

    while(i < (m-l+1)){
        a[k++] = temp1[i++];
    }

    while(j < (r-m)){
        a[k++] = temp2[j++];
    }
}

void mergesort(int a[], int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        #pragma omp parallel sections num_threads(1)
        {
            #pragma omp section
            {
                mergesort(a, l, mid);
            }

            #pragma omp section
            {
                mergesort(a, mid+1, r);
            }
        }
        merge(a, l, mid, r);
    }
}

int main(){
    double start = omp_get_wtime();
    int n = 1000000;
    int a[n];
    for(int i = 0; i < n; i++){
        a[i] = n - i;
    }
    mergesort(a, 0, n-1);
    printf("Time required = %f\n", omp_get_wtime() - start);
}
