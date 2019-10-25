
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