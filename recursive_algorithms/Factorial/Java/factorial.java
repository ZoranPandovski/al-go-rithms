// Sample Java Recursive Factorial Solution
// Main method shows example of how to call the recursive method and print out the answer.

public class Factorial{
    public static void main(String args){
        System.out.println(factorial(5));
    }

    public static long factorial(int n) {
        if (n <= 1)
            return 1;
        else
            return n * factorial(n - 1);
    }
}