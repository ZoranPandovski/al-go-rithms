import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0)
		{
		    int a = sc.nextInt();
		    int arr[][] = new int[a][a];
		    
		    for(int i=0;i<a;i++)
		    {
		        for(int j=0;j<a;j++)
		        {
		            arr[i][j]=sc.nextInt();
		        }
		    }
		    
		    for(int i=0;i<a;i++)
		    {
		        int k=i;
		        int j=0;
		        while(k>=0)
		        {
		            System.out.print(arr[j][k]+" ");
		            k-=1;
		            j+=1;
		        }
		    }
		    
		    for(int i=1;i<a;i++)
		    {
		        int k=i;
		        int j=a-1;
		        while(k<=a-1)
		        {
		            System.out.print(arr[k][j]+" ");
		            k+=1;
		            j-=1;
		        }
		        
		    }
		    
		    
		    
		    
		    System.out.println();
		}
	}
}
