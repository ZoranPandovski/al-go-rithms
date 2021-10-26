/*
Given a set of different numbers and a target sum 
check if the target sum can be made using those numbers.
*/
import java.util.*;
class Subset_Sum
{
    public static void main(String args[])
    {
        Scanner sc= new Scanner(System.in);
        int n,sum;
        System.out.println("Enter the required Sum: ");
        sum=sc.nextInt();
        System.out.println("Enter the number of different elements present : ");
        n=sc.nextInt();
        int num[]= new int[n];
        System.out.println("Enter the numbers available");
        for (int i =0; i<n; i++)
        {
            num[i]=sc.nextInt();
        }
        boolean flag= knapsack(num, n,sum);
        if (flag== true)
            System.out.println("Subset Sum is possible");
        else 
            System.out.println("Subset Sum NOT is possible");
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