import java.util.Scanner;

/**
 * Created by aubdira on 10/30/17.
 *
 * String permutation in java Given a string "ABC" OUTPUT ABC ACB BAC BCA CBA CAB
 */
public class StringPermutation {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter you string with out spaces: ");
        String givenString = scanner.next();
        scanner.close();

        System.out.println("The Permuted String:");

        StringPermutation.permuteString(givenString, 0, givenString.length() - 1);
    }

    /**
     * Permutation method
     *
     * @param str string to calculate permutation for
     * @param start starting index
     * @param end end index
     */
    private static void permuteString(String str, int start, int end) {
        if (start == end) {
            System.out.println(str);
        } else {
            for (int i = start; i <= end; i++) {
                str = swap(str, start, i);
                permuteString(str, start + 1, end);
                str = swap(str, start, i);
            }
        }
    }

    private static String swap(String str, int i, int j) {
        char temp;
        char[] charArray = str.toCharArray();
        temp = charArray[i];
        charArray[i] = charArray[j];
        charArray[j] = temp;
        return String.valueOf(charArray);
    }

}

