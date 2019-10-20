import java.io.*;
import java.util.*;

public class Solution {

   static boolean isAnagram(String A, String B) {
      
       char[] arrA = A.toUpperCase().toCharArray();
       char[] arrB = B.toUpperCase().toCharArray();
       Arrays.sort(arrA);
       Arrays.sort(arrB);
       
       for(int i = 0; i < A.length(); i++)
           try {
               if(Character.toUpperCase(arrA[i]) != Character.toUpperCase(arrB[i])) 
                  return false;
           } // end try
           catch(Exception e) {
               return false;
           } // end catch
       return true;
   } // end isAnagram
    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        String B=sc.next();
        boolean ret=isAnagram(A,B);
        if(ret)
           System.out.println("Anagrams");
        else 
           System.out.println("Not Anagrams");
        
    } // end main
} // end class
