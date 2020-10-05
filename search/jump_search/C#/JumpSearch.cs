using System;

public class JumpSearch
{
    // Testing the program.
    public static void Main(string[] args)
    {
        int[] arr = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
        int x = 55;
        int y = 14;
        Console.WriteLine(
            $"{JumpSearch(arr, x)}\n{JumpSearch(arr, y)}");
    }

    public static int JumpSearch(int[] array, int number)
    {
        Array.Sort(array);
        int n = array.Length;
        // Finding a block size to be jumped.
        int block = (int)(Math.Floor(Math.Sqrt(n)));
        int prev = 0;

        // Finding an index at which number is less than element at index.
        while (array[Math.Min(block, n) - 1] < number)
        {
            prev = block;
            block += block;
            if (prev >= n)
            {
                return -1;
            }
        }

        // Linear search for number in block beginning with prev.
        while (array[prev] < number)
        {
            prev++;
            if (prev == Math.Min(block, n))
            {
                return -1;
            }
        }

        return array[prev] == number ? prev : -1;
    }
}