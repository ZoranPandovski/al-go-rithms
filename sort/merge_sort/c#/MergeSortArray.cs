using System;

public class Program
{

	public static int[] MergeSort(int[] arr)
	{
		int Len = arr.Length;
		if(Len < 2)
		{
			return arr;
		}
		int MidIdx = Len/2;
		int[] LeftArr = new int[MidIdx];
		int[] RightArr = new int[Len-MidIdx];
		for(int i=0;i<Len;i++)
		{
			if(i < MidIdx)
			{
				LeftArr[i] = arr[i];
			}
			else
			{
				RightArr[i-MidIdx] = arr[i];
			}
		}

		return MergeArray(MergeSort(LeftArr), MergeSort(RightArr));
	}

	// function which merges 2 sorted arrays
	public static int[] MergeArray(int[] arr1, int[] arr2)
	{
		int Len1 = arr1.Length;
		int Len2 = arr2.Length;
		int arr1Idx = 0;
		int arr2Idx = 0;
		int[] MergedArray = new int[Len1 + Len2];

		for(int i=0;i<Len1+Len2;i++)
		{
			if(arr1Idx < Len1 && arr2Idx < Len2)
			{
				MergedArray[i] = arr1[arr1Idx] < arr2[arr2Idx] ? arr1[arr1Idx++] : arr2[arr2Idx++];
			}
			else if(arr1Idx < Len1)
			{
				MergedArray[i] = arr1[arr1Idx++];
			}
			else
			{
				MergedArray[i] = arr2[arr2Idx++];
			}
		}
		return MergedArray;
	}

	// Main function with tests
	public static void Main(string[] args)
	{
		int[] EmptyTestArray = new int[0];
		int[] TestArray = new int[]{5,3,8,1,3,6,9,7,2,4};
		int[] TestArray2 = new int[]{2,3,1};
		Console.WriteLine(ArrayToString(MergeSort(EmptyTestArray)));
		Console.WriteLine(ArrayToString(MergeSort(TestArray)));
		Console.WriteLine(ArrayToString(MergeSort(TestArray2)));
	}

	// Helper function to print out an array structure
	public static string ArrayToString(int[] arr)
	{
		return "[" + string.Join(",", arr) + "]";
	}
}