using System;

namespace InsertionSort 
{
  class InsertionSort {

    static int[] doInsertionSort(int[] arr)
    {
      for (int i = 0; i < arr.Length - 1; i++)
      {
        int j = i + 1;

        while (j > 0)
        {
          if (arr[j - 1] > arr[j])
          {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
          }
          j--;
        }
      }
      return arr;
    }

    static void Main(string[] args) 
    {
      int[] arr = new int[] {5, 3, 2, 123, 52134, 1, 0, -1};
      Console.WriteLine(string.Join(",", arr));
      Console.WriteLine(string.Join(",", doInsertionSort(arr)));
    }
  }
}
