/*
Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.
*/

// Java program for the above approach
import java.io.*;
import java.util.*;

class Solution{
      static void printUnion(int[] a, int n, int[] b, int m){
         HashSet<Integer> hs = new HashSet<>();
         for(int i = 0; i<n; i++){
            hs.add(a[i]);
         }
         for(int i = 0; i<m; i++){
            hs.add(b[i]);
         }
         return hs.size();
	    }

     public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[m];
        for(int i = 0; i<n; i++){
           a[i]=sc.nextInt();
        }
        for(int i = 0; i<m; i++){
           b[i]=sc.nextInt();
        }
        System.out.println(printUnion(a,n,b,m));
     }
}

