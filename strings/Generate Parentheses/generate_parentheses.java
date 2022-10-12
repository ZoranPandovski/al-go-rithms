/*
  Problem Statement: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
   
   Test Cases:- 
   1.
   Input: n = 3
   Output: ["((()))","(()())","(())()","()(())","()()()"]
   
   2.
   Input: n = 1
   Output: ["()"]
*/

class Solution {
    
    List<String> al = new ArrayList<>();
    public void myfunc(String ans,int o, int c){
        if(o==0 && c==0){
            if(!al.contains(ans))
            al.add(ans);
            return;
        }
        if(o==0){
            while(c-->0){
                ans+=")";
            }
            if(!al.contains(ans))
            al.add(ans);
            return;
        }
        
        if(o==c){
            ans+= "(";
            myfunc(ans,o-1,c);
        }else{
            myfunc(ans+"(",o-1,c);
        myfunc(ans+")",o,c-1);
        } 
        
    }
    public List<String> generateParenthesis(int n) {
        
        
        myfunc("",n,n);
        return al;
    }
}
