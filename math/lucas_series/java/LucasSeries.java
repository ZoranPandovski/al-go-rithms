import java.util.Scanner;

/**
 *
 * @author R. L. Ratcliffe
 * 
 * Iterative version of Lucas Sequence
 * 
 * Either enter a number as a command line argument
 * or enter a number when prompted to display n Lucas numbers.
 * 
 */
public class LucasSeries {

    public long iterativeLucas(long n) {

        long num = 2;
        long prevTerm = 1;
        long prevPrevTerm;

        if (n == 0) {
            return num;
        } else {
            for (long i = 1; i <= n; i++) {
                prevPrevTerm = num + prevTerm;
                num = prevTerm;
                prevTerm = prevPrevTerm;
            }
        }
        return num;

    }

    public static void main(String[] args) {
        LucasSeries ls = new LucasSeries();
        int n = 0;

        Scanner input = new Scanner(System.in);

        // If there is one argument, try to parse input as n
        // Otherwise, ask user to enter n
        // Amount of numbers starts at 0
        try {
            if (args.length == 1) {
                n = Integer.parseInt(args[0]);
            } else {
                System.out.println("Please enter how many numbers of the"
                                    + " Lucas series to be printed.");
                n = Integer.parseInt(input.next());
                System.out.println("");
            }
        } catch (NumberFormatException e) {
            System.err.println("Invalid amount for n.");
            System.exit(1);
        }

        // Print out sequence
        System.out.println("Here are " + n + " Lucas numbers:");
        for (long i = 0; i <= n; i++) {
            System.out.println(ls.iterativeLucas(i));
        }
    }

}
