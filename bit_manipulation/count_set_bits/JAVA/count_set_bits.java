import java.io.*;
class count_set_bits
{
	public static void main(String[] ar)
	{
		System.out.println(countSetBitsWithInBuiltMethod(10));
		System.out.println(countSetBitsWithoutInBuiltMethod(10));
		System.out.println(countSetBitsWithInBuiltMethod(100));
		System.out.println(countSetBitsWithoutInBuiltMethod(100));
	}
	public static int countSetBitsWithInBuiltMethod(int num)
	{
		return Integer.bitCount(num);
	}
	public static int countSetBitsWithoutInBuiltMethod(int num)
	{
		int c=0;
		while(num!=0)
		{
			num&=(num-1);
			c++;
		}
		return c;
	}
}