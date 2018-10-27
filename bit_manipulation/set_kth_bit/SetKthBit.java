// Java implementation to set the kth bit 

// of the given number 

public class SetKthBit { 

	// function to set the kth bit 

public static int setKthBit(int n, int k) {



	// kth bit of n is being set by this operation 

	return ((1 << k) | n); 

} 

// Driver code 

public static void main(String arg[]) {



	int n = 10, k = 2; 

	System.out.print("Kth bit set number = " + 

							setKthBit(n, k)); 

} 

} 

