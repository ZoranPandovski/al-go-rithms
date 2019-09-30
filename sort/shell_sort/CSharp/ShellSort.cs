

using System;
using System.Collections.Generic;

namespace shellsort
{
    class ShellSort
    {
        static void Main(string[] args)
        {
            List<int> myList = new List<int>() { 3, 9, 1, 2, 5, 100, 2123, 54, 34, 123, 534 };

            Console.WriteLine("List before");
            PrintList(myList);

            Shell_Sort(myList);

            Console.WriteLine("List after sort");
            PrintList(myList);

            Console.WriteLine("Press enter when done");
            Console.ReadLine();
        }

        public static void Shell_Sort(List<int> list)
        {
            int index = list.Count;

            while (index > 0)
            {
                int index2 = index;
                while (index2 < list.Count)
                {
                    int k = list[index2];
                    int index3 = index2;
                    while (index3 >= index && k < list[index3 - index])
                    {
                        list[index3] = list[index3 - index];
                        index3 -= index;
                    }
                    list[index3] = k;
                    index2 += 1;
                }
                index = (index / 2);
            }
            //return list;
        }

        public static void PrintList(List<int> list)
        {
            foreach (int item in list)
            {
                Console.Write(item + " ");
            }
            Console.WriteLine();
        }
    }
}
