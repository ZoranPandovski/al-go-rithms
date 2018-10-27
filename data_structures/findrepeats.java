# Find the number of Repeating occurences of an element in an integer array

import java.util.*;

public class finddups {	

	public static void main(String[]args)
	{
		HashMap<Integer,Integer>map = new HashMap<>();
		HashMap<Integer,Integer>count = new HashMap<>();
		int Arr[] =  {1,2,3,4,5,5,5,8,4,4};
	
		for (int i = 0 ; i < 10 ; i++)
		{
			 if (!map.containsKey(Arr[i]))
			 {
				 map.put(Arr[i], 1);
				 count.put(Arr[i], 1);
			 }
			 else
			 {
				 
				 if (!count.containsKey(Arr[i]))
				 {
					 count.put(Arr[i], 1);
					
				 }
				 else
				 {
				 count.put(Arr[i],count.get(Arr[i]) + 1);
				 
				 }
				 
				 
			 }
			
	     }
			
		for (HashMap.Entry<Integer, Integer> entry : count.entrySet()) {
			System.out.println("Array Element"+ " "+ entry.getKey() + " is repeated " + entry.getValue()+ " times");
		}
		
	}
	
}
