// Reversing an array using Java collections.

/*
use the function java.util.Collections.reverse(List list) method. 
This method reverses the elements in the specified list. 
Hence, we convert the array into a list first by using java.util.Arrays.asList(array) 
and then reverse the list. 
*/

import java.util.*;

public class reversingArray {

	/*function reverses the elements of the array*/
	static void reverse(Integer a[])
	{
		Collections.reverse(Arrays.asList(a));
		System.out.println(Arrays.asList(a));
	}

	public static void main(String[] args)
	{
		Integer [] arr = {10, 20, 30, 40, 50};
		reverse(arr);
	}
}
