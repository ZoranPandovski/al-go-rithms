import java.lang.*;
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;
public class karger
{
	public static int [][] merge(int a[][],int rn1,int rn2)
	{
		int i,len;
		int k=0;
		
		for(i=a[rn1-1][0]+2;i<a[rn1-1][0]+2+a[rn2-1][0];i++)
		{
			a[rn1-1][i]=a[rn2-1][i-a[rn1-1][0]]; 
			a[rn2-1][i-a[rn1-1][0]]=0;
		}
		a[rn1-1][0]+=a[rn2-1][0];
		a[rn2-1][0]=0;
		
		for(i=2;i<a[rn1-1][0]+2;i++)
			if(a[rn1-1][i]==rn1 || a[rn1-1][i]==rn2)
				a[rn1-1][i]=0;
		
		len=a[rn1-1][0];
		int temp[]=new int[len];
		
		for(i=2;i<a[rn1-1][0]+2;i++)
			if(a[rn1-1][i]!=0)
				temp[k++]=a[rn1-1][i];
		
		a[rn1-1][0]=k;
		
		for(i=2;i<len+2;i++)
			a[rn1-1][i]=temp[i-2];
		
		return a;
	}
	public static int no_of_rows(int arr[][])
	{
		int i,l=0;
		for(i=0;i<arr.length;i++)
			if(arr[i][0]!=0)
			l++;
		return l;
	}
	public static void main(String args[])
	{
		String str="";
		int i,j,z,rn1,rn2,col_len;
		int nodes=8;
		int min_cut=nodes;
		Scanner sc=new Scanner(System.in);
		int a[][]=new int[nodes][nodes*nodes];
		for(i=0;i<nodes;i++)
		{
			str=sc.nextLine();
			str=str+" ";
			while(str.length()>0)
			{
			str.trim();
			
			a[i][++a[i][0]]=Integer.parseInt(str.substring(0,str.indexOf(' ')));
			str=str.substring(str.indexOf(' ')+1);
			}
		}
		System.out.println();

		for(i=0;i<nodes;i++)
		a[i][0]-=1;


		int [][] backup_a = new int[a.length][];
		for(int y = 0; y < a.length; y++)
		    backup_a[y] = a[y].clone();

		for(z=1;z<=nodes*nodes;z++)
		{
			for(int y = 0; y < backup_a.length; y++)
			    a[y] = backup_a[y].clone();

			col_len=no_of_rows(a);
			while(col_len>2)
			{
				rn1=ThreadLocalRandom.current().nextInt(1,nodes+1);
				rn2=ThreadLocalRandom.current().nextInt(1,nodes+1);
				
				while(a[rn1-1][0]==0)
				rn1=ThreadLocalRandom.current().nextInt(1,nodes+1);
				while(a[rn2-1][0]==0 || rn1==rn2)
				rn2=a[rn1-1][ThreadLocalRandom.current().nextInt(2,a[rn1-1][0]+2)];

				for(i=0;i<nodes;i++)
				{
					if(i==(rn1-1) || i==(rn2-1))
					continue;
					for(j=2;j<(2+a[i][0]);j++)
					if(a[i][j]==rn2)
					a[i][j]=rn1;
				}
				a=merge(a,rn1,rn2);
				col_len=no_of_rows(a);
			}

			i=0;
			while(true)
			{
				if(a[i][0]!=0)
				{
					if(a[i][0]<min_cut)
						min_cut=a[i][0];
					break;
				}
				i++;
			}
		}
		System.out.println("Minimum Cut="+min_cut);
	}
}        
// import java.lang.*;
// import java.util.Scanner;
// import java.util.concurrent.ThreadLocalRandom;
// public class karger
// {
// 	public static int [][] merge(int a[][],int rn1,int rn2)
// 	{
// 		int i,len;
// 		int k=0;
		
// 		for(i=a[rn1-1][0]+2;i<a[rn1-1][0]+2+a[rn2-1][0];i++)
// 		{
// 			a[rn1-1][i]=a[rn2-1][i-a[rn1-1][0]]; 
// 			a[rn2-1][i-a[rn1-1][0]]=0;
// 		}
// 		a[rn1-1][0]+=a[rn2-1][0];
// 		a[rn2-1][0]=0;
		
// 		for(i=2;i<a[rn1-1][0]+2;i++)
// 			if(a[rn1-1][i]==rn1 || a[rn1-1][i]==rn2)
// 				a[rn1-1][i]=0;
		
// 		len=a[rn1-1][0];
// 		int temp[]=new int[len];
		
// 		for(i=2;i<a[rn1-1][0]+2;i++)
// 			if(a[rn1-1][i]!=0)
// 				temp[k++]=a[rn1-1][i];
		
// 		a[rn1-1][0]=k;
		
// 		for(i=2;i<len+2;i++)
// 			a[rn1-1][i]=temp[i-2];
		
// 		return a;
// 	}
// 	public static int no_of_rows(int arr[][])
// 	{
// 		int i,l=0;
// 		for(i=0;i<arr.length;i++)
// 			if(arr[i][0]!=0)
// 			l++;
// 		return l;
// 	}
// 	public static void main(String args[])
// 	{
// 		String str="";
// 		int i,j,z,rn1,rn2,col_len;
// 		int min_cut=8;
// 		Scanner sc=new Scanner(System.in);
// 		int a[][]=new int[8][100];
// 		for(i=0;i<8;i++)
// 		{
// 			str=sc.nextLine();
// 			str=str+" ";
// 			while(str.length()>0)
// 			{
// 			str.trim();
			
// 			a[i][++a[i][0]]=Integer.parseInt(str.substring(0,str.indexOf(' ')));
// 			str=str.substring(str.indexOf(' ')+1);
// 			}
// 		}
// 		System.out.println();

// 		for(i=0;i<8;i++)
// 		a[i][0]-=1;


// 		int [][] backup_a = new int[a.length][];
// 		for(int y = 0; y < a.length; y++)
// 		    backup_a[y] = a[y].clone();

// 		for(z=1;z<=500;z++)
// 		{
// 			for(int y = 0; y < backup_a.length; y++)
// 			    a[y] = backup_a[y].clone();

// 			// System.out.println(z);

// 			col_len=no_of_rows(a);
// 			while(col_len>2)
// 			{
// 				rn1=ThreadLocalRandom.current().nextInt(1,9);
// 				rn2=ThreadLocalRandom.current().nextInt(1,9);
				
// 				while(a[rn1-1][0]==0)
// 				rn1=ThreadLocalRandom.current().nextInt(1,9);
// 				while(a[rn2-1][0]==0 || rn1==rn2)
// 				rn2=a[rn1-1][ThreadLocalRandom.current().nextInt(2,a[rn1-1][0]+2)];

// 				for(i=0;i<8;i++)
// 				{
// 					if(i==(rn1-1) || i==(rn2-1))
// 					continue;
// 					for(j=2;j<(2+a[i][0]);j++)
// 					if(a[i][j]==rn2)
// 					a[i][j]=rn1;
// 				}
// 				a=merge(a,rn1,rn2);
// 				col_len=no_of_rows(a);
// 			}

// 			i=0;
// 			while(true)
// 			{
// 				if(a[i][0]!=0)
// 				{
// 					if(a[i][0]<min_cut)
// 						min_cut=a[i][0];
// 					break;
// 				}
// 				i++;
// 			}
// 		}
// 		System.out.println("Minimum Cut="+min_cut);
// 	}
// }        
