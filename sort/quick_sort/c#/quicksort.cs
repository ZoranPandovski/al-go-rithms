using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Quicksort
{
	class Program
	{
		static void Main(string[] args)
		{
			int[] arr = { 123, 12, 912, 16, 83, 1, -12, 1203};

			Console.WriteLine(string.Join(",", arr));

			Quicksort(arr, 0, arr.Length - 1);

			Console.WriteLine(string.Join(",", arr));
		}

		public static void Quicksort(int[] arr, int left, int right)
		{
			int i = left, j = right;
			int pivot = arr[(left + right) / 2];

			while (i <= j)
			{
				while (arr[i].CompareTo(pivot) < 0)
				{
					i++;
				}

				while (arr[j].CompareTo(pivot) > 0)
				{
					j--;
				}

				if (i <= j)
				{
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;

					i++;
					j--;
				}
			}

			if (left < j)
			{
				Quicksort(arr, left, j);
			}
			if (i < right)
			{
				Quicksort(arr, i, right);
			}
		}
	}
}
