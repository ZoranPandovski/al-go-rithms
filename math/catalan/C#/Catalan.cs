using System;

/// <summary>
/// Simple algorithm for a Catalan Number generator
/// </summary>
public class Catalan
{
	public static void main(String [] args) 
	{
		int n;
		if (UInt32.TryParse(Console.ReadLine(), out n))
		{
			Console.WriteLine(catalan(n));	
		}
	}

	private static uint catalan(uint n)
	{
		uint res = 0;

		if (n <= 1)
		{
			return 1;
		}
		for (uint i = 0; i < n; i++)
		{
			res += catalan(i) * catalan(n - i - 1);
		}
		return res;
	}
}