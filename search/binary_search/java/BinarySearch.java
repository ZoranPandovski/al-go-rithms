
class BinarySearch
{
    //Search for a number in an array
    protected static int search(int arr[], int x)
    {
        return binarySearch(arr, 0, arr.length-1, x);
    }

    // Returns index of x if it is present in the array, else returns -1
    private static int binarySearch(int arr[], int start, int end, int x)
    {
        if (start<=end)
        {
            int mid = start + (end - start)/2;

            if (arr[mid] == x)
                return mid;

            if (arr[mid] > x)
                return binarySearch(arr, start, mid-1, x);

            return binarySearch(arr, mid+1, end, x);
        }

        return -1;
    }

    public static void main(String args[])
    {
        int arr[] = {2, 3, 7, 8, 78, 99, 102, 5555};
        int x = 102;
        int result = search(arr, x);
        if (result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element found at index "+ result);
    }
}