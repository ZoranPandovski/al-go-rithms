import java.util.Scanner;

public class IsPalindromeWithStringBuilder {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String value = in.next(); // add string
    System.out.println(isPalindromeWithStringBuilder(value) ? "is Palindrome" : "Not Palindrome");
  }


  //simple realization with StringBuilder
  private static boolean isPalindromeWithStringBuilder(String value) {
    return new StringBuilder(value).reverse().toString().equals(value);
  }
}
