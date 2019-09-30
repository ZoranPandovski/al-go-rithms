import java.util.Arrays;
import java.util.Scanner;

public class AnagramDetector {

	public static void main(String[] args) {

		Scanner in = new Scanner(System.in);
		String anagram;

		while (!(anagram = in.nextLine()).isEmpty()) {

			String[] words = anagram.split("\\?");
			checkAnagram(words[0].trim(), words[1].trim());
		}
	}

	public static void checkAnagram(String w1, String w2) {

		char[] cw1 = w1.toCharArray();
		char[] cw2 = w2.toCharArray();
		Arrays.sort(cw1);
		Arrays.sort(cw2);
		if (Arrays.equals(cw1, cw2)) {
			System.out.println(w1 + " is an anagram of " + w2);
		} else {
			System.out.println(w1 + " is NOT an anagram of " + w2);
		}
	}
}
