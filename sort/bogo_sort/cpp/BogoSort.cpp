#include <iostream>

bool isSorted(int *arr, size_t size) {
    if (size == 1 || size == 0) {
        return true;
    }
    if (arr[size - 1] < arr[size - 2]) {
        return false;
    }
    return isSorted(arr, size-1);
}

void randomize(int *arr, size_t size) {
    int temp, random;
    for (int i = 0; i < size; i++) {
        random = rand() % size;
        temp = arr[i];
        arr[i] = arr[random];
        arr[random] = temp;
    }
}

void bogoSort(int *arr, size_t size) {
    int counter = 1;
    while (!isSorted(arr, size) ) {
        randomize(arr, size);
        std::cout << "Bogo Sort Pass " << counter << ":" << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        counter++;
        std::cout << std::endl;
    }
}

int main()
{
    int intArr[] = { 8,7,6,5,4};
    std::cout << "Bogo Sort / Permutation Sort" << std::endl;
    bogoSort(intArr, 5);
    return 0; 
}