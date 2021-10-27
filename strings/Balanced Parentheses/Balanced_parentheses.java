import java.util.*;

public class Balanced_parentheses {
    


    public static Boolean is_balanced(String exp) {
        //Stack stk = new Stack()
        Stack<Character> stk = new Stack<Character>();
        Map<Character, Character> map = new HashMap<>();
        map.put(')','(');
        map.put('}','{');
        map.put(']','[');


        int len = exp.length();
        if(len % 2 == 1){return false;}

        for(int i = 0; i <len; i++) {
            char c = exp.charAt(i);
            if(c == '(' | c== '{' | c== '['){ 
                stk.push(c);
            } else if(stk.isEmpty()){
                return false;
            } else { // c must be closing char
                char matchOfc = map.get(c);
                char onStack = stk.pop();
                if(matchOfc != onStack) {
                    return false;
                }
            }
        }  


        return true;
        
    }

    public static void main(String[] args) {
      String test1 = "[((()))]" ;
      String test2 = "[(({}))]" ;
      String test3 = "[{((){})}]"; 

      String fail1 = "[[[]]";
      String fail2 = "[[[]])";
      String fail3 = "[[]{}[)]])";

      if(!is_balanced(test1)){System.out.println("oh no");}
      if(!is_balanced(test2)){System.out.println("oh no");}
      if(!is_balanced(test3)){System.out.println("oh no");}
      
      if(is_balanced(fail1)){System.out.println("oh no");}
      if(is_balanced(fail2)){System.out.println("oh no");}
      if(is_balanced(fail3)){System.out.println("oh no");}

      System.out.println("yay");

    } 

/*
Given an expression string exp , 
write a program to examine whether the pairs and the orders of 
“{“,”}”,”(“,”)”,”[“,”]” are correct in exp

    Declare a character stack S.
    Now traverse the expression string exp. a) If the current character is a starting bracket (‘(‘ or ‘{‘ or ‘[‘) then push it to stack. b) If the current character is a closing bracket (‘)’ or ‘}’ or ‘]’) then pop from stack and if the popped character is the matching starting bracket then fine else parenthesis are not balanced.
    After complete traversal, if there is some starting bracket left in stack then “not balanced”

*/

}
