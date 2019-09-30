using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EuclidGCD
{
    class EuclidGCD
    {
        static int CalculateGCD(int a, int b)
        {
            if (b == 0)
            {
                return a;
            }

            else
            {
                int c = a % b;
                return CalculateGCD(b, c);
            }
        }
    }
}

