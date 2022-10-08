import java.util.Scanner;
// example factorial of 5 is 120 i.e 5*4*3*2*1
// negative numbers do not have a factorial 


public class Main {

    // if base case is not true use backtracking and find factorial unit we hit base case
    public static int calculateFactorial(int n) {
        // base case factorial of 0 is 1 always
        if (n == 0)
            return 1;
        return n * calculateFactorial(n - 1);
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int n = scn.nextInt();
        System.out.println(calculateFactorial(n));
    }
}
