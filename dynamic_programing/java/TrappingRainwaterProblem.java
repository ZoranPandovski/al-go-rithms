import java.util.Scanner;

public class TrappingRainwaterProblem {

    public static void main(String[] args)
    {
        final Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the size of the bars:");
        int length = scanner.nextInt();
        int bars[] = new int [length];
        System.out.println("Enter the elements of the bars:");

        for(int i=0; i<length; i++) {
            bars[i] = scanner.nextInt();
        }
        System.out.println("The maximum water that can be trapped is: " + getMaxWater(bars, length));
    }

    public static int getMaxWater(int[] bars, int length)
    {
        if(length < 3) {
            return 0;
        }
        int[] leftMax = new int [length];
        int[] rightMax = new int [length];
        leftMax[0] = 0;
        int maxWater = 0;
        for(int i = 1; i<length; i++) {
            leftMax[i] = Math.max(bars[i], leftMax[i-1]);
        }
        rightMax[length-1] = bars[length-1];
        for(int i = length-2; i>=0; i--) {
            rightMax[i] = Math.max(bars[i], rightMax[i+1]);
        }
        for(int i = 1; i<length-1; i++) {
            maxWater += (Math.min(leftMax[i], rightMax[i]) - bars[i]);  // amount of water obtained will be difference of ith bar and the minimum of leftmost & rightmost bar
        }
        return maxWater;
    }
}
