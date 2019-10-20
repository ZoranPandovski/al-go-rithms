
class BinarySearch
{
    //Search for a number in an array
    protected static int search(int array[], int number)
    {
        return binarySearch(array, 0, array.length-1, number);
    }

    // Returns index of x if it is present in the array, else returns -1
    private static int binarySearch(int array[], int start, int end, int number)
    {
        if (start <= end)
        {
            int middle = start + (end - start)/2;

            if (arr[middle] == number)
                return middle;

            if (arr[middle] > number)
                return binarySearch(array, start, middle - 1, number);

            return binarySearch(array, middle + 1, end, number);
        }

        return -1;
    }

    public static void main(String args[])
    {
        int array[] = {2, 3, 7, 8, 78, 99, 102, 5555};
        int numberToFind = 102;
        int result = search(array, numberToFind);
        if (result == -1)
            System.out.println("Element not present");
        else
            System.out.println("Element found at index " + result);
    }
}
