using System;

/// <summary>
/// Algorithm to tell if a given number is Armstrong or not
/// </summary>
public class ArmstrongNumber 
{
	public static void main(string[] args)
	{
		var number = Console.ReadLine();
		if (IsArmstrongNumber(number))
		{
			Console.WriteLine($"Number {number} is Armstrong");
		} 
		else 
		{
			Console.WriteLine($"Number {number} is not Armstrong");
		}
	}

	public static bool IsArmstrongNumber(string number)
	{
		ulong sum = 0;
		foreach (var digit in number)
		{
			var num = Convert.ToUInt64(digit) - 48;
			sum += (ulong)Math.Pow(num, number.Length);
		}

		return sum.ToString().Equals(number);
	}
}