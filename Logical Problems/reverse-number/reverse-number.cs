// C# program to reverse a number
using System;

class GFG {
	// Iterative function to
	// reverse digits of num
	static int reverseDigits(int num)
	{
		int rev_num = 0;
		while (num > 0) {
			rev_num = rev_num * 10 + num % 10;
			num = num / 10;
		}
		return rev_num;
	}

	// Driver code
	public static void Main()
	{
		int num = 4562;
		Console.Write("Reverse of no. is "
					+ reverseDigits(num));
	}
}

// This code is contributed by Sam007
