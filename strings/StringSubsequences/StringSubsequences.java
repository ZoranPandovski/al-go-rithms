package strings.StringSubsequences;

import java.util.*;

class StringSubsequences {

  static List<String> al = new ArrayList<>();

  static void findsubsequences(String s, String ans) {
    if (s.length() == 0) {
      al.add(ans);
      return;
    }
    findsubsequences(s.substring(1), ans + s.charAt(0));
    findsubsequences(s.substring(1), ans);
  }

  public static void main(String[] args) {
    String s = "abcd";
    findsubsequences(s, "");
    System.out.println(al);
  }
}