package strings.countPalindromicSubstring;

import java.util.*;

public class palindromicSubsequences {
  static ArrayList<String> al = new ArrayList<>();

  static boolean isPallindrome(String s) {
    if (s.length() == 1)
      return true;
    if (s == "")
      return false;
    boolean result = true;
    int i = 0, j = s.length() - 1;
    while (i < j) {
      if (s.charAt(i) != s.charAt(j))
        result = false;
      i++;
      j--;
    }
    return result;
  }

  static void findSubsequence(String s, String ans) {
    if (s.length() == 0) {
      if (isPallindrome(ans))
        al.add(ans);
      return;
    }
    findSubsequence(s.substring(1), ans + s.charAt(0));
    findSubsequence(s.substring(1), ans);
  }

  static long countPS(String str) {
    findSubsequence(str, "");
    long result;
    result = al.size();
    return result;
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String s = sc.nextLine();
    long ans = countPS(s);
    System.out.println(ans);
  }
}