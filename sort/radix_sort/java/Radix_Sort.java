package core;

import java.util.Arrays;

public class Radix_Sort {
	
	//Find the maximum value in an array
	public static int findMaximum(int[] array){
		int max = array[0];
		for(int i = 0; i < array.length; i++){
			if(array[i] > max){
				max = array[i];
			}
		}
		return max;
	}
	
	public static int getDigit(int n, int d){
		return (n/d) % 10;
	}
	
	public static void sortRound(int[] array, int p){
		//Defined above to speed up process
		int i;
		//Returned list
		int[] result = new int[array.length];
		//Create a list of number frequencies
		int[] frequencyList = new int[10];
		//Sets frequencies to 0
		Arrays.fill(frequencyList, 0);
		
        for (i = 0; i < array.length; i++){
        	//Add 1 to the frequency of p digit number.
            frequencyList[getDigit(array[i], p)]++;
        }
        
        for(i = 1; i < 10; i++){
        	frequencyList[i] += frequencyList[i-1];
        }
        
        for(i = array.length - 1; 0 <= i; i--){
        	//Add value to resulting list
        	result[frequencyList[getDigit(array[i], p)] - 1] = array[i];
        	//Remove occurrence from frequency list
        	frequencyList[getDigit(array[i], p)]--;
        }
        
        //Update the original array to the
        //resulting array.
        for(i = 0; i < array.length; i++){
        	array[i] = result[i];
        }
	}
	
	public static void sort(int[] array){
		int max = findMaximum(array);
		
		for(int p = 1; /* Integer division */ max / p > 0; p *= 10){
			sortRound(array, p);
		}
	}
	
}
