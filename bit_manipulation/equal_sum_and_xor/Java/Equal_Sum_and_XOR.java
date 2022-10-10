import java.util.Scanner;

class algo{
    public static long Equal_Sum_and_XOR(int n){
        int count=0;
        while(n>0){
            if(n%2==0)
                count++;
            n/=2;
        }
        return 1L<<count;
    }
	public static void main (String[] args) throws java.lang.Exception{
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long ans=Equal_Sum_and_XOR(n);
        System.out.println(ans);
	}
}

// Time complexity O(lg(n))
// Space Complexity O(1)

/*
    Description:
    * Using the identity n+x = n^x + 2*(n&x), we see that n+x = n^x holds iff n&x=0.
    * Hence, in order to obtain n&x=0, for every set bit of n, the corresponding bit of x should be unset.
    * For every unset bit of n, the bit of x has 2 possibilities, 1 or 0.
    * Hence the required ans is Math.pow(2,no of unset bits)*Math.pow(1,no of set bits) = pow(2,no of unset bits)
    * Also for faster implementation, we use 1L<<k instead of Math.pow(2,k)
*/