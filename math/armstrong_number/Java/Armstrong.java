
/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
/* Name of the class has to be "Main" only if the class is public. */
class Armstrong
{
	public static boolean isArmstrong(String num){

		BigInteger sumVal = BigInteger.valueOf(0);
		int numOfDigits = num.length();
		for(int i=0;i<numOfDigits;i++){
			String dig = "";
			dig += num.charAt(i);
			BigInteger digit = new BigInteger(dig);
			sumVal = sumVal.add(digit.pow(numDigits));
		}
		if(sumVal.toString().equals(num)){
			return true;
		}
		return false;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		// System.out.println(isArmstrong("1634"));
		if(isArmstrong("1634")){
			System.out.println("Number is Armstrong");
		}
		else{
			System.out.println("Number is not Armstrong");	
		}
	}
}