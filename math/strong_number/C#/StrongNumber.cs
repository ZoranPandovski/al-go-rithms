using System;

public class StrongNumber
{
    /// <summary>
    /// Calculates whether or not a number is a strong number.
    /// </summary>
    /// <param name="number">The number which may be determined to be a strong number. </param>
    /// <returns>Returns true if number is a strong number.</returns>
    public static bool IsStrongNumber(int number)
    {
        int expectedResult = number;
        int sumofDigitFactorials = 0;
        while (number > 0)
        {
            int digit = number % 10; // Extract the last digit
            int digitFactorial = Factorial(digit); // Calculate the factorial of the last digit
            sumofDigitFactorials += digitFactorial;
            number /= 10; // Remove the last digit
        }
        return sumofDigitFactorials == expectedResult;
    }
    /// <summary>
    /// Returns the factorial of an integer.
    /// </summary>
    /// <param name="numberToFactorialize">The integer to factorialize</param>
    /// <returns>The factorial of numberToFactorialize.</returns>
    private static int Factorial(int numberToFactorialize)
    {
        int result = numberToFactorialize;
        if (numberToFactorialize == 0) // Base case
        {
            return 1;
        }

        else // Recursive calculation of the factorial for all other cases; x * (x - 1) * (x - 2) and so on
        {
            return numberToFactorialize * Factorial(numberToFactorialize - 1);
        }
    }
}
