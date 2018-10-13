import java.util.*;
public class palindrome {
    public static boolean isPalindrome(String str) {
        str=str.toLowerCase();
	String backwards = "";
	int len = str.length();

	for (int i = len-1; i >= 0; i--){
	    backwards += str.charAt(i);
	}

	if (str.equals(backwards)){
	    return true;
	}
	else {
	    return false;
	}
    }
    
	
	
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        String str=sc.next();
        System.out.println(isPalindrome(str));
    }
    }
