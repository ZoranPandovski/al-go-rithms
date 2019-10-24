import java.util.Scanner;
import java.util.Stack;
import java.util.HashMap;
 
public class BalancedParentheses {
    
    public static boolean isBalanced(String s) {
        HashMap<Character, Character> bracketsDictionary = new HashMap<Character, Character>();
        bracketsDictionary.put(')', '(');
        bracketsDictionary.put(']', '[');
        bracketsDictionary.put('}', '{');
        
        Stack<Character> stack = new Stack<Character>();
        boolean isBalanced = true;
        
        for (Character ch: s.toCharArray()) {
           if (bracketsDictionary.containsKey(ch)) {
               if (stack.empty()) {
                   return false;
               }
               if (bracketsDictionary.get(ch) != stack.pop()) {
                   return false;
               }
               
           } else {
               stack.add(ch);   
           }
        }
        
        return true;
    }
    
    public static void main(String[] args) {
        System.out.println(isBalanced("[]([{({([()])})}]){()}"));
    }
}