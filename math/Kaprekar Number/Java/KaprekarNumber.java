import java.util.Scanner;
import java.lang.Math;
class KaprekarNum
{
	public static void main(String[] args) 
	{
		Scanner scn = new Scanner(System.in);
		System.out.print("Sample Input: ");
		int N = scn.nextInt();
		int n = N;
		int dig = 0;
		while(n>0)
		{
			n/=10;
			dig+=1;
		}

		int lastNDig = (N*N) % (int)Math.pow(10,dig);
		int firstDigs = ((N*N) - lastNDig)/ (int)Math.pow(10,dig);

		if (N == lastNDig+firstDigs)
		{
			System.out.println("Kaprekar Number");
		}

		else
		{
			System.out.println("Not a Kaprekar Number");
		}

	}
}
