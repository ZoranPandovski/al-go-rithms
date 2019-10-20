using System;
using System.Linq;

public class Program
{
	public static void Main()
	{
		Console.WriteLine("Please enter a number / text");
		string input = Console.ReadLine();
		
		string output = IsPalindrome(input) ? "Input is a palindrome" : "Input is not a palindrome";
		Console.WriteLine(output);
	}

	public static bool IsPalindrome(string input)
	{
		int length = input.Length;
		for (int i = 0; i < length / 2; i++)
		{
			if (input[i] != input[length - i] - 1)
				return false;
		}

		return true;
	}

	/// <summary>
	/// An alternative approach that uses LINQ to determine if the input string is a palindrome 
	/// </summary>
	public static bool IsPalindromeLINQ(string input)
	{
		return input.SequenceEqual(input.Reverse());
	}
}