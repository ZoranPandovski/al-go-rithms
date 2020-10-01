// Optimized java implementation
// of Bubble sort
import java.io.*;

public class BubbleSort
{
    // An optimized version of Bubble Sort
    static void bubbleSort(int arr[], int n)
    {
        int i, j, temp;
        boolean swapped;
        for (i = 0; i < n - 1; i++)
        {
            swapped = false;
            for (j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    System.out.println("\nSwapped " + arr[j] + " with " +  arr[j + 1]);
                    // swap arr[j] and arr[j+1]
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
                    printArray(arr, arr.length);
                }
            }

            // IF no two elements were
            // swapped by inner loop, then break
            if (swapped == false)
                break;
        }
    }

    // Function to print an array
    static void printArray(int arr[], int size)
    {
        int i;
        for (i = 0; i < size; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }

    // Driver program
    public static void main(String args[])
    {
        System.out.println("\nOriginal array: ");
        int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
        printArray(arr, arr.length);
        int n = arr.length;
        bubbleSort(arr, n);
        System.out.println("\nSorted array: ");
        printArray(arr, n);
    }
}


// This code is contributed
// by Nikita Tiwari.
