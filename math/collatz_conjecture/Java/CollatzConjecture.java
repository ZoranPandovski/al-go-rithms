// Program to print the number of steps a number takes to reach 1 according to the rules given by Collatz Conjecture. 
// Rules: If n is even: Divide n by 2 else multiply n with 3 and then add 1. Repeat these steps until the current n reaches 1.
// The conjecture part here is that no matter what number we choose, it always reaches 1. The conjecture here is that no one knows the proof for this.

public class CollatzConjecture {

    public static void main(String[] args) {
        // Input tests
        if (args.length != 1) {
            System.out.println("Please pass only one argument to the program");
            System.exit(1);
        }
        if (args.length == 1 && !isInteger(args[0], 10)) {
            System.out.println("Please pass an integer to the program");
            System.exit(1);
        }
        if (args.length == 1 && isInteger(args[0], 10) && Integer.parseInt(args[0]) <= 0) {
            System.out.println("Please pass a non-zero integer to the program");
            System.exit(1);
        }

        int n = Integer.parseInt(args[0]);
        System.out.println(collatz(n));
    }

    private static int collatz(int n) {
        int count = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;

            } else {
                n = 3 * n + 1;

            }
            count++;
        }
        return count;
    }

    // https://stackoverflow.com/questions/5439529/determine-if-a-string-is-an-integer-in-java
    private static boolean isInteger(String s, int radix) {
        if (s.isEmpty())
            return false;
        for (int i = 0; i < s.length(); i++) {
            if (i == 0 && s.charAt(i) == '-') {
                if (s.length() == 1)
                    return false;
                else
                    continue;
            }
            if (Character.digit(s.charAt(i), radix) < 0)
                return false;
        }
        return true;
    }
}