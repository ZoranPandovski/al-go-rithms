import java.util.Scanner;

public class IsPalindromeWithArray {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String value = in.next(); // add string
    System.out.println(isPalindromeWithArray(value) ? "is Palindrome" : "Not Palindrome");
  }


  //most fastest realization with array
  private static boolean isPalindromeWithArray(String value) {
    char[] chars = value.toCharArray();
    for (int i = 0; i < chars.length / 2; i++) {
      if (chars[i] != chars[chars.length - 1 - i]) {
        return false;
      }
    }
    return true;
  }
}
