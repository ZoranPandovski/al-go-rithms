import java.util.Scanner;

class hp2{
    public static int Highest_Power_of_2(int n){
        return n&(~(n-1)); 
    }
	public static void main (String[] args) throws java.lang.Exception{
		Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println(Highest_Power_of_2(n));
	}
}

// Time complexity: O(1)
// Space complexity: O(1)

/*
    Description:
    *This program calculates the highest power of 2 less than the given n.
    *The idea is to subtract calculate n&(~(n-1)) which would make all bits of the number 0 except the leading 1.
    *Thus the number is reduced to the greatest power of 2 less than it.
*/