import java.util.Scanner;
// example aba is palindrome
// abc is not a palindrome


// this code checks whether a string is palindrome or not using recursion
// this code also has passed all test cases on geeks for geeks

public class Main {

    // it simply checks for the characters at left and right pointer
    // and if there are not equal then we simply return false else we go on checking
    // and the base case is when left and right pointer overlap it means
    // string traversal is over and we return true
    public static boolean checkPalindrome(String s,int startIndex,int endIndex)
    {
        if(startIndex>endIndex)
            return true;
        if(s.charAt(startIndex)!=s.charAt(endIndex))
            return false;
        else return checkPalindrome(s,++startIndex,--endIndex);
    }

    public static void main(String[] args) {
        Scanner scn=new Scanner(System.in);
        String s=scn.next();
        System.out.println(checkPalindrome(s,0,s.length()-1));
        scn.close();
    }
}
