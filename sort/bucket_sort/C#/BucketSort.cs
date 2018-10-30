using System;
using System.Collections.Generic;

namespace Algorithms
{
    class BucketSort
    {
        static int[] Sort(int[] numbers)
        {
            int minValue = numbers[0];
            int maxValue = numbers[0];

            for (int i = 1; i < numbers.Length; i++)            
            {
                if (numbers[i] > maxValue) maxValue = numbers[i];
                if (numbers[i] < minValue) minValue = numbers[i];
            }

            List<int>[] buckets = new List<int>[maxValue - minValue + 1];

            for (int i = 0; i < buckets.Length; i++)
            {
                buckets[i] = new List<int>();
            }

            for (int i = 0; i < numbers.Length; i++)
            {
                buckets[numbers[i] - minValue].Add(numbers[i]);
            }

            int k = 0;

            for (int i = 0; i < buckets.Length; i++)
            {
                if (buckets[i].Count > 0)
                {
                    for (int j = 0; j < buckets[i].Count; j++)
                    {
                        numbers[k] = buckets[i][j];
                        k++;
                    }
                }
            }

            return numbers;
        }

        static void Main(string[] args)
        {
            int[] numbers = { 1, 9, -4, 15, 79, 2, 4, -10 };
            numbers = Sort(numbers);

            foreach (var number in numbers)
            {
                Console.WriteLine(number);
            }
        }
    }
}
