using System;
namespace Application
{
    public class Factorial
    {

        public static int GetFactorial(int n)
        {
            int product = 1;

            for (int i = 2; i <= n; i++)
            {
                product *= i;
            }

            return product;
        }


    }
}
