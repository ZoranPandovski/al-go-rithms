import java.io.*;
import java.util.*; 

/*
 * Question - Geek has a string Sof size Nconsisting of characters from '0'to '9'. 
 * He wants to minimise the length of the string. In each minimising operation,
 * geek can remove any two consecutive characters if they are of the form {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"}.
 * Find the minimum possible length of the string after applying minimising operations. 
 * 
 * Example
Input: 
N = 5 
S = "12213"

Output: 1

Explanation: Geek can get the string of 
length 1 in two minimising operation,
In 1st operation Geek will remove "12" 
from "12213" then Geek left with "213"
In 2nd operation Geek will remove "21" 
from "213" then Geek left with "3"

Time Complexity: O(N)
Space Complexiy: O(N)
 */
class Solution { 
    public int minLength(String s, int n) { 
    	// code here 
   // if difference is mod(1) or mod(9), remove both numbers
    	
    	// 1st store the toCheck patterns in hashset
    	HashSet<String> toCheck = new HashSet<>();
    	toCheck.add("12");
    	toCheck.add("21");
    	toCheck.add("34");
    	toCheck.add("43");
    	toCheck.add("56");
    	toCheck.add("65");
    	toCheck.add("78");
    	toCheck.add("87");
    	toCheck.add("09");
    	toCheck.add("90");
    	
    	//StringBuilder sb1 = new StringBuilder("12"); // delete
    	//System.out.println("toCheck "+toCheck.contains(sb1.toString()));
    	
    	// create a stack to compare the adjacent elements of the given String
    	Stack<Character> st = new Stack<>();
    	
 
    	
    	//ArrayList<Character> chArr = s.toCharArray();
    	//st.push(s.charAt(0));
		//traverse through the string chars
    	for( int i=0;i<s.length();i++){
    	    //System.out.println("i="+i+" stack ="+st.toString());

			// if stack is not empty, compare the top element + the nxt char in string and check if it exists in the hashset.
    	    if(!st.isEmpty()){
    	        StringBuilder sb = new StringBuilder();
    	        sb.append(st.peek());
    	        sb.append(s.charAt(i));
    	        //System.out.println("sb is "+sb.toString()+" toCheck.contains(sb)="+toCheck.contains(sb));
    	        if(toCheck.contains(sb.toString())){
    	            st.pop();
    	            
    	        }
    	        else{
					//if 
    	            st.push(s.charAt(i));
    	        }
    	    }
    	    else{
    	        st.push(s.charAt(i));
    	       
    	    }
    	}
    	
    	return st.size();
    	
    	
    }
}
    

public class MinimizeStringUsingStack {


    public static void main(String args[]) throws IOException { 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t > 0){
            int n = Integer.parseInt(br.readLine());
            String s = br.readLine();
            Solution ob = new Solution();
            System.out.println(ob.minLength(s, n));
            t--;
        }
    } 
} 
