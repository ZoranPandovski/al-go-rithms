import java.util.*;

class Fibonacci {

    static int nth_fibonacci(int n) {
        if(n<=1) {
            return n;
        }

        // Create dp array
        int dp[] = new int[n + 1];

        // Initialise first two elements
        dp[0] = 0;
        dp[1] = 1;

        // Build dp array
        for(int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return nth element
        return dp[n];
    }

    public static void main(String[] args) {
        int n = 4;
        System.out.println(nth_fibonacci(n)); // 3
    }
}