
class BinarySearch
{
    // Returns index of x if it is present in the array, else returns -1
    private static int binarySearch(int arr[], int start, int end, int x)
    {
        if (start<=end)
        {
            int mid = start + (end - start)/2;

            if (arr[mid] == x)
                return mid;

            // If the element is smaller than mid, then it can only be present in the left sub-array
            if (arr[mid] > x)
                return binarySearch(arr, start, mid-1, x);

            // Else the element can only be present in the right sub-array
            return binarySearch(arr, mid+1, end, x);
        }

        return -1;
    }

    public static void main(String args[])
    {
        int arr[] = {2, 3, 7, 8, 78, 99, 102, 5555};
        int x = 3;
        int result = binarySearch(arr,0, arr.length-1, x);
        if (result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element found at index "+ result);
    }
}