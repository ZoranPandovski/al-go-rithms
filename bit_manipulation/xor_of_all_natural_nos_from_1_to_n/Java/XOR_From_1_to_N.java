import java.util.Scanner;
 
class algo{
	public static int XOR_From_1_to_N(int n){
		if(n%4==0)
			return n;
		if(n%4==1)
			return 1;
		if(n%4==2)
			return n+1;
		return 0;
	}
 
	public static void main (String[] args){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int ans=XOR_From_1_to_N(n);
		System.out.println(ans);
	}
}

// Time Complexity: O(1)
// Space Complexity: O(1)

/*
    Description:
    *When we do XOR of numbers, we get 0 as the XOR value just before a multiple of 4. 
    *This keeps repeating before every multiple of 4. (XOR of numbers upto 4k+3 is 0)
    *Using this fact, we can find the XOR of numbers of the form 4k,4k+1 and 4k+2.
*/