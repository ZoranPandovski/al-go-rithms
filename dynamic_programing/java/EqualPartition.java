//DP program to check if an array of integers can be divided into 2 equal partitions
import java.util.*;
class Tab_Equal_Partition
{
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        int n,sum;
        System.out.println("Enter the size of array : ");
        n=sc.nextInt();
        int num[]= new int[n];
        sum=0;
        System.out.println("Enter the numbers available");
        for (int i =0; i<n; i++)
        {
            num[i]=sc.nextInt();
            sum= sum+num[i];
        }
        if (sum%2 != 0)
            System.out.println("Equal Partition NOT is possible");
        else
        {
            boolean flag= knapsack(num, n,sum/2);
            if (flag== true)
                System.out.println("Equal Partition is possible");
            else 
                System.out.println("Equal Partition NOT is possible");
        }
    }
    public static boolean knapsack(int num[], int n, int sum)
    { 
        boolean t[][]= new boolean[n+1][sum+1];
        for (int i = 0; i <= n; i++)  
        { 
            for (int j = 0; j <= sum; j++)  
            {     
                if (j==0) 
                    t[i][j]= true;
                else if (i==0 && j!=0)
                    t[i][j]= false;
                else if (num[i-1] <= j) 
                    t[i][j]=(t[i-1][j-num[i-1]]) || t[i-1][j];
                else 
                    t[i][j]= t[i-1][j];
            }
        }
        return t[n][sum];
    }
}