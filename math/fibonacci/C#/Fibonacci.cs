using System;
using System.Collections.Generic;

namespace Fibonacci
{
    class Fibonacci
    {
        static void Main(string[] args)
        {

            Console.Write("How many Fibonacci numbers do you want?\n");
            int n;
            while (!int.TryParse(Console.ReadLine(), out n))
            {
                Console.Write("Please, insert a number\n");
            }

            foreach (int i in GetFibonacciSequence(n))
            {
                Console.WriteLine(i);
            }

            Console.ReadLine();
        }

        public static List<int> GetFibonacciSequence(int n)
        {

            List<int> fib = new List<int>();
            fib.Add(1);
            fib.Add(1);

            for (int i = 2; i <= n; i++)
            {
                fib.Add(fib[i - 2] + fib[i - 1]);
            }

            return fib;
        }

    }
}
