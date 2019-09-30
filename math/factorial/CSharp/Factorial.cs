

using System;

namespace factorial
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("4! = " + Factorial(4));
            Console.WriteLine("8! = " + Factorial(8));
            Console.WriteLine("12! = " + Factorial(12));

            Console.WriteLine("Press enter when done");
            Console.ReadLine();
        }

        public static long Factorial(int number)
        {
            long sum = 1;
            for (int i = 2; i <= number; i++)
            {
                sum = sum * i;
            }
            return sum;
        }
    }
}
