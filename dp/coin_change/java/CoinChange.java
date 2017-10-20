import java.util.Arrays;
 
class CoinChange
{
    static long countWays(int S[], int m, int n)
    {
        long[] table = new long[n+1];
 
        Arrays.fill(table, 0);   //O(n)
 
        table[0] = 1;
 
        for (int i=0; i<m; i++)
            for (int j=S[i]; j<=n; j++)
                table[j] += table[j-S[i]];
 
        return table[n];
    }
 
    public static void main(String args[])
    {
        int arr[] = {1, 2, 3};
        int m = arr.length;
        int n = 4;
        System.out.println(countWays(arr, m, n));
    }
}
