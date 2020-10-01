/*
Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N(the size of array). The second line of each test case contains array elements.

Output:
For each test case print the required answer in new line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ Ai ≤ 106

Example:
Input:
2
7
1 101 2 3 100 4 5
4
10 5 4 3

Output:
106
10

Explanation:
Testcase 1: All the increasing subsequences are : (1,101); (1,2,3,100); (1,2,3,4,5). Out of these (1, 2, 3, 100) has maximum sum,i.e., 106.
*/
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
    		
    	Scanner in=new Scanner(System.in);
    	int T=in.nextInt();
    	for(int i=0;i<T;i++){
    		
    		int n=in.nextInt();
    		int arr[]=new int[n];
    		
    		for(int j=0;j<n;j++){
    		    arr[j]=in.nextInt();
    		}
    		int tab[]=arr.clone();
    		int maxval=arr[0];
    		for(int k=1;k<n;k++){
    		    for(int l=0;l<k;l++){
    		        if((arr[k]>arr[l])&&(tab[k]<tab[l]+arr[k])){
    		            tab[k]=tab[l]+arr[k];
    		            if(tab[k]>maxval){
    		                maxval=tab[k];
    		            }
    		            
    		        }
    		    }
    		}
    		System.out.println(maxval);
    		
    	}
	}
}
