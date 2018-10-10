#include <stdio.h>


int main()
{
    int arr[20];
    int i, size, pos;

    printf("Enter size of the array : ");
    scanf("%d", &size);
    printf("Enter elements in array : ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element position to delete : ");
    scanf("%d", &pos);


    if(pos < 0 || pos > size)
    {
        printf("Invalid position! Please enter position between 1 to %d", size);
    }
    else
    {
        for(i=pos-1; i<size-1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    printf("\nElements of array after delete are : ");
    for(i=0; i<size; i++)
    {
        printf("%d  ", arr[i]);
    }

    return 0;
}
