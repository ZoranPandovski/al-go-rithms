import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Stack;

/**
 * Problem Statement: Given a Knapsack of a maximum capacity of W and N items each with its own value and weight, 
 * throw in items inside the Knapsack such that the final contents has the maximum value.
 *
 * Credits to http://rerun.me/2014/05/27/the-knapsack-problem/ for the clean solution.
 */

public class Knapsack {

    public static void main(String[] args) throws Exception {
        int value[] = {10, 40, 30, 50};
        int weight[] = {5, 4, 6, 3};
        int W = 10;

        System.out.println(knapsack(value, weight, W));
    }

    public static int knapsack(int value[], int weights[], int W) {
        
        int N = weights.length;
        
        int[][] dp = new int[N + 1][W + 1];

        for (int item = 1; item <= N; item++) {
            for (int weight = 1; weight <= W; weight++) {

                //Is the current item's weight less
                //than or equal to running weight
                if (weights[item - 1] <= weight) {

                    //Given a weight, check if the value of the current item + value of the item that we could afford
                    // with the remaining weight is greater than the value without the current item itself
                    dp[item][weight] = Math.max(
                            value[item - 1] + dp[item - 1][weight - weights[item - 1]],
                            dp[item - 1][weight]);
                } else {
                    //If the current item's weight is more than the
                    //running weight, just carry forward the value
                    //without the current item
                    dp[item][weight] = dp[item - 1][weight];
                }
            }

        }

        //Printing the matrix of values which we calculated.
        for (int[] rows : dp) {
            for (int col : rows) {
                System.out.format("%5d", col);
            }
            System.out.println();
        }

        return dp[N][W];
    }

}
