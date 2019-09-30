

using System;
using System.Collections.Generic;

namespace Linear_Search
{
    class Linear_Search
    {
        static void Main(string[] args)
        {
            List<int> myList = new List<int>() { 3, 9, 1, 2, 5, 100, 2123, 54, 34, 123, 534 };

            Console.Write("List = ");
            PrintList(myList);

            int index = LinearSearch(myList, 1);
            Console.WriteLine("1 found at " + index);

            index = LinearSearch(myList, 4);
            Console.WriteLine("4 found at " + index);

            Console.WriteLine("Press enter when done");
            Console.ReadLine();
        }

        public static int LinearSearch(List<int> list, int target)
        {
            for (int i = 0; i < list.Count; i++)
            {
                if (list[i] == target)
                {
                    return i;
                }
            }
            return -1;
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
