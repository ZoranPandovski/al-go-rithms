import java.io.*;
import java.util.*;

/*
 * The current problem was a part of one of the GFG contests -
 * 
 * Problem - 
 * You are given an array of N elements and NUM queried, In each query you are given 3 numbers L,R and K.
 * You have to tell, how many indexes are there in between L and R (L<=i<=R) such that the frequency of a[i] from index i to n-1 is k.
 * 
 * Note : 0 based indexing
 * 
 * Example -
 * N=5, NUM=3
 * A={1,1,3,4,3}
 * Q={{0,2,2},{0,2,1},{0,4,2}}
 * Output : {2, 1, 2}
 * 
 * Explanation : for query 1 : 0 2 2
 * L=0, R=2, K=2
 * let L<=i<=R
 * for i=0, frequency of a[i] i.e 1 from i to n-1 is 2.
 * for i=1, frequency of a[i] i.e 1 from i to n-1 is 1.
 * for i=2, frequency of a[i] i.e 3 from i to n-1 is 2.
 * hence we have 2 elements from index 0 to 2 whose frequency from i o n-1 is 2.
 * 
 * Please find my implementation for the above problem under the Solution class, under method - solveQueries()
 */
class Solution {
    public static ArrayList<Integer> solveQueries(int N, int num, int[] A, int[][] Q) {
        // code here
        
        ArrayList<Integer> res = new ArrayList<>();
        // fetch the L, R and K
        
        //query traversal
        for(int x=0;x<num;x++){
            
            int numCount =0;
            
            int L = Q[x][0];
            int R = Q[x][1];
            int K = Q[x][2];
            
            // L<=i<=R
            for(int i=L;i<=R;i++){
                int ele = A[i];
                // now find the freq of A[i] from i to N-1
                int count =0;
                for(int j=i;j<=(N-1);j++){
                    if(A[j]==ele){
                        count++;
                    }
                }
				// check if the frequency == K
                if(count==K){
                    numCount++;
                }
                
            }
            res.add(numCount);
        }
        return res;
        
    }
}
/*
    Constraints:
      1<=N<=10^3
      1<=Q<=10^3
      1<=A[i]<=10^5
      
      
     Test Case 1:
      Input: N=5, num=3 , int[] A = {1,1,3,4,3}, int[][] Q={{0,2,2},{0,2,1},{0,4,2}}
      Output : res={2,1,2}

     Test Case 1:
      Input: N=5, num=2 , int[] A = {1,1,1,1,1}, int[][] Q={{0,4,4},{0,4,5}}
      Output : res={1,1}
     
    */ 
        

class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);

        return a;
    }

    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }

    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}


class IntMatrix
{
    public static int[][] input(BufferedReader br, int n, int m) throws IOException
    {
        int[][] mat = new int[n][];

        for(int i = 0; i < n; i++)
        {
            String[] s = br.readLine().trim().split(" ");
            mat[i] = new int[s.length];
            for(int j = 0; j < s.length; j++)
                mat[i][j] = Integer.parseInt(s[j]);
        }

        return mat;
    }

    public static void print(int[][] m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }

    public static void print(ArrayList<ArrayList<Integer>> m)
    {
        for(var a : m)
        {
            for(int e : a)
                System.out.print(e + " ");
            System.out.println();
        }
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int N;
            N = Integer.parseInt(br.readLine());
            
            
            int num;
            num = Integer.parseInt(br.readLine());
            
            
            int[] A = IntArray.input(br, N);
            
            
            int[][] Q = IntMatrix.input(br, num, 3);
            
            Solution obj = new Solution();
            ArrayList<Integer> res = obj.solveQueries(N, num, A, Q);
            
            IntArray.print(res);
            
        }
    }
}


