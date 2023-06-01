import java.util.*;
/**
 * The KadanesAlgorithm class implements the Kadane's algorithm to find the maximum subarray sum in an array.
 */

public class KadanesAlgorithm {
    /**
     * Finds the maximum subarray sum using Kadane's algorithm.
     *
     * @param A The input array.
     * @return The maximum subarray sum.
     */
    public static int maxSubArray(int[] A) {
        // Variable to track the maximum sum found so far
        int maxSoFar = A[0];
        
        // Variable to track the maximum sum ending at the current position
        int maxEndingHere = A[0]; 

        for (int i = 1; i < A.length; i++) {
            // Calculate the maximum sum ending at the current position
            // It can be either the current element itself or the sum of the current element and the previous maximum sum ending at the previous position
            maxEndingHere = Math.max(maxEndingHere + A[i], A[i]);

            // Update the maximum sum found so far
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }

        return maxSoFar; // Return the maximum sum found in the entire array
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            System.out.print("Enter the length of the array: ");
            int length = sc.nextInt();

            int[] arr = new int[length];
            System.out.println("Enter the array elements:");

            for (int i = 0; i < length; i++) {
                arr[i] = sc.nextInt();
            }

            int maxSum = maxSubArray(arr);
            System.out.println("Maximum subarray sum: " + maxSum);
            
        }
    }
}