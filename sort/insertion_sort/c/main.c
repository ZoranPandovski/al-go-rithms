#include <stdio.h>

void insertionSort(int nums[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = nums[i];
       j = i - 1;
       while (j >= 0 && nums[j] > key)
       {
           nums[j + 1] = nums[j];
           j = j - 1;
       }
       nums[j + 1] = key;
   }
}
 
// Helpter function to print the array
void printArray(int nums[], int n)
{
   int i;
   for (i = 0; i < n; i++)
       printf("%d ", nums[i]);
   printf("\n");
}
 
int main()
{
    // Usage and test

    int nums[] = {122, 111, 3, 125, 6, 21, 13, 13, 8};
    int len = sizeof(nums) / sizeof(nums[0]);
 
    printf("unsorted: ");
    printArray(nums, len); 
    insertionSort(nums, len);
    printf("sorted: ");
    printArray(nums, len);
    return 0;
}
