#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo (int x) {
    /**
     * Function to check if a given number is a power of 2 
     *      x              : checks if x == 0 and 
     *      !(x & (x - 1)) : checks if x is a power of 2 
     */
    return (x && !(x & (x - 1)));
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    if (isPowerOfTwo(num)) 
        printf("Given number is a power of 2\n");
    else 
        printf("Given number is not a power of 2\n");

    return 0;
}