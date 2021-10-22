import java.util.Stack;

public class IsBalancedParenthesis {

	private static boolean sol(String parenthesis) {
		// TODO Auto-generated method stub
		
		Stack<Character> s = new Stack<>();
		for(int i = 0; i < parenthesis.length(); i++) {
			char ci = parenthesis.charAt(i);
			
			if(ci == '[' || ci == '{' || ci == '(') {
				s.push(ci);
			} else if(ci == ')' || ci == '}' || ci == ']'){
				
				if(s.isEmpty()) {
					return false;
				} 
				
				char topCh = s.pop();
				
				if(topCh == '(' && ci == ')') {
					continue;
				} 
				
				if(topCh == '{' && ci == '}') {
					continue;
				} 
				
				if(topCh == '[' && ci == ']') {
					continue;
				}
				
				return false; 
			}
		}
		
		if(s.isEmpty()) {
			return true;
		} else {
			return false;
		}

	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		System.out.println(sol("}}}"));
	}

}
