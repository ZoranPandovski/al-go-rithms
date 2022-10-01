using System;
using System.Numerics;

namespace NthFibonacci
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Enter a number to find the nth of the Fibonacci sequence.");
            
            string input = Console.ReadLine();
            
            if (input != null)
            {
                if (BigInteger.TryParse(input, out BigInteger nth) == false)
                {
                    Console.WriteLine("That is not a number!");
                }
                else
                {
                    if (nth < 0)
                    {
                        Console.WriteLine("The number must be positive.");
                    }
                    else
                    {
                        Console.WriteLine(Fibonacci.NthFib(nth));
                    }
                }
            }
            else
            {
                Console.WriteLine("Please enter a number.");
            }
        }
    }
}