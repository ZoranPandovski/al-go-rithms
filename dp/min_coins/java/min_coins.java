// A Dynamic Programming based program to find
// minimum of coins to make a given change V 
import java.io.*; 
  
class min_coins
{ 
    // m is size of coins array (number of different coins) 
    static int minCoins(int coins[], int m, int V) 
    { 
        // table[i] will be storing the minimum number of coins 
        // required for i value. So table[V] will have result 
        int table[] = new int[V + 1]; 
  
        // Base case (If given value V is 0) 
        table[0] = 0; 
  
        // Initialize all table values as Infinite 
        for (int i = 1; i <= V; i++) 
        table[i] = Integer.MAX_VALUE; 
  
        // Compute minimum coins required for all 
        // values from 1 to V 
        for (int i = 1; i <= V; i++) 
        { 
            // Go through all coins smaller than i 
            for (int j = 0; j < m; j++) 
            if (coins[j] <= i) 
            { 
                int sub_res = table[i - coins[j]]; 
                if (sub_res != Integer.MAX_VALUE  
                       && sub_res + 1 < table[i]) 
                       table[i] = sub_res + 1;     
            } 
        } 
        return table[V]; 
    } 
  
    // Driver program  
    public static void main (String[] args)  
    { 
        int coins[] = {1, 5, 10, 25, 50};  
        int m = coins.length; 
        int V = 199; 
        if(m <= 0)
        {
            System.out.println("Must have some coin denominations");
        }
        else
        {
            System.out.print( "Minimum number of coins required to make " + V + " using ");
            if(m > 2)
            {
                for (int i = 0; i < m-1; i++)
                {
                    System.out.print ("" + coins[i] + ", ");
                }
                System.out.print ("and " + coins[m-1] + " ");
            }
            else
            {
                if(m == 1)
                    System.out.print(coins[0] + " ");
                if(m == 2)
                    System.out.print(coins[0] + " and " + coins[1] + " ");
            }
            System.out.println("is " + minCoins(coins, m, V) + " coins."); 
        }
    }
} 
