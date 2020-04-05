using System.Numerics;

namespace NthFibonacci
{
    public class Fibonacci
    {
        public static BigInteger NthFib(BigInteger nth)
        {
            if (nth > 1)
            {
                return NthFib(nth - 1) + NthFib(nth - 2);
            }

            return nth;
        }
    }
}