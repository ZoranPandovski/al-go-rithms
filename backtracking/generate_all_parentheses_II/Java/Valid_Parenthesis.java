import java.util.ArrayList;
import java.util.Scanner;


/**
 *   we are building the string from scratch. Under this approach, we add
 *   left and right parens, as long as our expression stays valid.
 *   On each recursive call, we have the index for a particular character in the string. We need to select either a
 *   left or a right paren. When can we use a left paren, and when can we use a right paren?
 *   1. Left Paren: As long as we haven't used up all the left parentheses, we can always insert a left paren.
 *   2. Right Paren: We can insert a right paren as long as it won't lead to a syntax error. When will we get a
 *   syntax error? We will get a syntax error if there are more right parentheses than left.
 *   So, we simply keep track of the number of left and right parentheses allowed. If there are left parens
 *   remaining, we'll insert a left paren and recurse. If there are more right parens remaining than left (i.e., if
 *   there are more left parens in use than right parens), then we'll insert a right paren and recurse.
 */
public class ValidParenthesis {

    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number : ");
        n = sc.nextInt();
        ArrayList<String> ans = generateParanthesis(n);
        for (String an : ans) {
            System.out.println(an);
        }
    }

    private static ArrayList<String> generateParanthesis(int n){
        char[] str = new char[n*2];
        ArrayList<String> list = new ArrayList<>();
        addParen(list, n, n, str, 0);
        return list;
    }

    private static void addParen(ArrayList<String> list, int leftRem, int rightRem, char[] str, int index) {

        if(leftRem < 0 || rightRem < leftRem)      //Invalid State
            return;

        if(leftRem == 0 && rightRem == 0)         //Out of left and right parenthesis
            list.add(String.copyValueOf(str));

        else{
            str[index] = '(';                    //Add left Parenthesis and recurse
            addParen(list, leftRem-1, rightRem, str, index+1);

            str[index] = ')';                   //Add right Parenthesis and recurse
            addParen(list, leftRem, rightRem-1, str, index+1);
        }
    }
}

