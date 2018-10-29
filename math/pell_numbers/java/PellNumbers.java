import java.util.Scanner;

/**
 *
 * @author R. L. Ratcliffe
 * 
 * Iterative version of Pell Sequence/Numbers
 * 
 * Either enter a number as a command line argument
 * or enter a number when prompted to display n Pell numbers.
 * 
 */
public class PellNumbers {

    public long iterativePellNums(long n) {

        long num = 0;
        long prevTerm = 1;
        long prevPrevTerm = 2;

        if (n <= 2) {
            return n;
        } else {

            for (long i = 3; i <= n; i++) {

                num = (2 * (prevPrevTerm)) + prevTerm;
                prevTerm = prevPrevTerm;
                prevPrevTerm = num;

            }

        }
        return num;
    }

    public static void main(String args[]) {
        PellNumbers pn = new PellNumbers();
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
                        + " Pell sequence to be printed.");
                n = Integer.parseInt(input.next());
                System.out.println("");
            }
        } catch (NumberFormatException e) {
            System.err.println("Invalid amount for n.");
            System.exit(1);
        }

        // Print out sequence
        System.out.println("Here are " + n + " Pell numbers:");
        for (long i = 0; i < n; i++) {
            System.out.println(pn.iterativePellNums(i));
        }

    }

}
