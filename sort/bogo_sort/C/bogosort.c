#include<stdio.h>
#include<stdlib.h>

int sorted (int *array, int size) {
    while (size >= 1) {
        if (array[size] < array[size-1]) return 0;
        size--;
    }
    return 1;
}

void shuffle (int *array, int size) {
    int i, tmp, random;
    for (i = 0; i < size; i++) {
        tmp = array[i];
        random = rand()%size;
        array[i] = array[random];
        array[random] = tmp;
    }
}

void bogosort (int *array, int size) {
    while (!sorted(array, size)) shuffle(array, size);
}

void print_array (int *array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int i, size;
    printf("Enter array size: ");
    scanf("%d", &size);
    int array[size];
    for (i = 0; i < size; i++) {
        array[i] = rand()%100;
    }
    printf("Original array: \n");
    print_array(array, size);
    bogosort(array, size);
    printf("Sorted array: \n");
    print_array(array, size);
    return 0;
}