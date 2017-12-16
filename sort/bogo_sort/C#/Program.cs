using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BogoSort
{
    //Shuffle Array
    static class RandomExtensions
    {
        public static void Shuffle<T>(this Random rng, T[] array)
        {
            int n = array.Length;
            while (n > 1)
            {
                int k = rng.Next(n--);
                T temp = array[n];
                array[n] = array[k];
                array[k] = temp;
            }
        }
    }

    static class Program
    {


        //Check if array is sorted
        public static bool IsSorted(int[] arr)
        {
            for (int i = 1; i < arr.Length; i++)
            {
                if (arr[i - 1] > arr[i])
                {
                    return false;
                }
            }
            return true;
        }

        //Print list
        private static void printList(int[] list)
        {
            for (int i = 0; i < list.Length-1; i++)
            {
                Console.Write(list[i] + ",");
            }
            Console.Write(list[list.Length - 1] + "\n");
        }

        static void Main(string[] args)
        {
            //Creating Random object
            Random rnd = new Random();

            //Creating an array 
            int[] list = new int[5];
            //Initializing an array with random numbers
            for (int i = 0; i < list.Length; i++)
            {
                list[i] = rnd.Next(1, 100);
            }
            //Print list
            printList(list);
            //Bogo Sort
            while (!IsSorted(list))
            {
                new Random().Shuffle(list);
            }
            //Print Sorted List
            printList(list);
        }


    }
}

