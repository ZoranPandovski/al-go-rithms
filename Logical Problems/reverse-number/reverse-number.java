// Java program to reverse a number

class GFG {
	/* Iterative function to reverse
	digits of num*/
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
	public static void main(String[] args)
	{
		int num = 4562;
		System.out.println("Reverse of no. is "
						+ reverseDigits(num));
	}
}

// This code is contributed by Anant Agarwal.
