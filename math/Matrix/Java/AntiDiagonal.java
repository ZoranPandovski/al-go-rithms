import java.util.*;
import java.lang.*;
import java.io.*;

class AntiDiagonal 
{
	public static void main (String[] args) 
	{
		Scanner sc = new Scanner(System.in);

		    int size = sc.nextInt();
		    int arr[][] = new int[size][size];
		    
		    for(int i=0;i<size;i++)
		    {
		        for(int j=0;j<size;j++)
		        {
		            arr[i][j]=sc.nextInt();
		        }
		    }
		    
		    for(int i=0;i<size;i++)
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
		    
		    for(int i=1;i<size;i++)
		    {
		        int k=i;
		        int j=size-1;
		        while(k<=size-1)
		        {
		            System.out.print(arr[k][j]+" ");
		            k+=1;
		            j-=1;
		        }
		        
		    }
		    System.out.println();
	}
}
