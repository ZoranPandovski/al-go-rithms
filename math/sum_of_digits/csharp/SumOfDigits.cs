using System;

public class SumOfDigits
{

    public static void main(String[] args)
    {
        int sum = SumOfDigits.sumOfDigits(25114);
        Console.Write(sum);
    }

    private static int SumOfDigits(int i)
    {
        int res = 0;
        while ((i != 0))
        {
            res = (res + (i % 10));
            10;
        }

        return res;
    }
}