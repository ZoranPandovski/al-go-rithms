
package greedyalgos;
import java.util.Scanner;
import java.lang.*;
import java.io.*;


public class LongestCommonSubsequence {
        int L[][] ;
/*LongestCommonSubsequence(int m,int n)
{
    int L[][] = new int[m+1][n+1];

}*/
    int lcs( char[] X, char[] Y, int m, int n )
  {
   L = new int[m+1][n+1];
 
   
    for (int i=0; i<=m; i++)
    {
      for (int j=0; j<=n; j++)
      {
        if (i == 0 || j == 0)
            L[i][j] = 0;
        else if (X[i-1] == Y[j-1])
            L[i][j] = L[i-1][j-1] + 1;
        else
            L[i][j] = max(L[i-1][j], L[i][j-1]);
      }
    }
  return L[m][n];
  }
 
  void printLCS(int m,int n,char[] X,char[] Y)
  {
     int lim=n*m;
     int i=m,j=n;
     String str="";
     while(i>0 && j>0)
     {
         if(X[i-1] == Y[j-1])
         {
             str=str+X[i-1];
             j=j-1;
             i=i-1;
         }
         else if (L[i-1][j] > L[i][j-1])
                i--;
         else
                j--;
     }
     StringBuilder in=new StringBuilder();
     in.append(str);
     System.out.println("String is:"+in.reverse());
  }
  int max(int a, int b)
  {
    return (a > b)? a : b;
  }
  
  
 
  public static void main(String[] args)
  {
   // LongestCommonSubsequence lcs = new LongestCommonSubsequence();
      Scanner sc=new Scanner(System.in);
      System.out.println("Input the string1:");
    String s1 = sc.next();
    System.out.println("Input the string2:");
    String s2 = sc.next();
 
    char[] X=s1.toCharArray();
    char[] Y=s2.toCharArray();
    int m = X.length;
    int n = Y.length;
    LongestCommonSubsequence lcs = new LongestCommonSubsequence();
    System.out.println("Length of LCS is" + " " +
                                  lcs.lcs( X, Y, m, n ) );
    lcs.printLCS(m,n,X,Y);
  }

    
}
