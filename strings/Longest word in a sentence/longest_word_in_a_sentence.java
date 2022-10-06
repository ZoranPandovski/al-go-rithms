import java.util.Scanner;

public class Main {
    // simply we have splitted the input string into arrays of strings 
    // and we have a max length which will keep track of max length word in the string
    static int LongestWordLength(String str) {
        String[] words = str.split(" ");
        int length = 0;

        for (String word : words) {
            if (length < word.length()) {
                length = word.length();
            }
        }
        return length;
    }

    public static void main(String args[]) {
        Scanner scn = new Scanner(System.in);
        String str = scn.next();

        System.out.println("The Length of the Longest word in a sentence is "+LongestWordLength(str));
        scn.close();
    }
}
