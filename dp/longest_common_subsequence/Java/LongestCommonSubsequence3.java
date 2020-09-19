
package greedyalgos;
import java.util.Scanner;
import java.lang.*;
import java.io.*;
public class LongestCommonSubsequence3 {
    int L[][][];
    
    int lcs3(int m,int n,int o,char[] X,char[] Y,char[] Z)
    {
        L=new int[m+1][n+1][o+1];
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=o;k++)
                {
                    if(i==0 || j==0 || k==0)
                        L[i][j][k]=0;
                    else if((X[i-1]==Y[j-1]) && (Y[j-1]==Z[k-1]))
                        L[i][j][k]=L[i-1][j-1][k-1] + 1;
                    else
                        L[i][j][k] = (int)Math.max(Math.max(L[i-1][j][k],L[i][j-1][k]), L[i][j][k-1]);
                }
            }
            
        }
        return L[m][n][o];
    }
    
   /* int max(int a,int b,int c)
    {
        int m1=a>b?a:b;
        int m2=1>b?m1:b;
        return m2;
    }*/
    void printLCS3(int m,int n,int o,char[] X,char[] Y,char[] Z)
    {
       String S="";
       int i=m,j=n,k=o;
       while(i>0 && j>0 && k>0) 
       {
           if((X[i-1]==Y[j-1]) && (X[i-1]==Z[k-1]))
           {
               S=S+X[i-1];
               i=i-1;
               j=j-1;
               k=k-1;
           }
           else if((L[i-1][j][k]>L[i][j][k-1]) || (L[i-1][j][k]>L[i][j-1][k]))
               i=i-1;
           else if((L[i][j-1][k]>L[i][j][k-1]) || (L[i][j-1][k]>L[i-1][j][k]))
               j=j-1;
           else 
               k=k-1;
       }
       
       StringBuilder in=new StringBuilder();
       in.append(S);
       
       System.out.println("LCS for 3 strings is:"+in.reverse());
    }
    
    
    public static void main(String []args)
    {
        Scanner sc=new Scanner(System.in);
        LongestCommonSubsequence3 obj=new LongestCommonSubsequence3();
        System.out.println("Input String1:");
        String s1=sc.next().trim();
        System.out.println("Input String2:");
        String s2=sc.next().trim();
        System.out.println("Input String3:");
        String s3=sc.next().trim();
        
        char X[]=s1.toCharArray();
        char Y[]=s2.toCharArray();
        char Z[]=s3.toCharArray();
        
        int m=X.length;
        int n=Y.length;
        int o=Z.length;
        
        System.out.println("Lenght of subsequence:"+obj.lcs3(m,n,o,X,Y,Z));
        obj.printLCS3(m,n,o,X,Y,Z);
    }

    
}
