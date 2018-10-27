/* Returns the best obtainable price for a rod of length n and 
   price[] as prices of different pieces */
int cutRod(int value[], int size) 
{ 
   int dp[size+1]; 
   dp[0] = 0; 
   // Build the table val[] in bottom up manner and return the last entry 
   // from the table 
   for (int i = 1; i<=size; i++) 
   { 
       int max_val = INT_MIN; 
       for (int j = 0; j < i; j++) 
         max_val = max(max_val, value[j] + dp[i-j-1]); 
       dp[i] = max_val; 
   } 
  
   return dp[size]; 
} 
 
