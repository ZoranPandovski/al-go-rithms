class Solution {
     
    public boolean wordBreak(String s, List<String> wordDict) {
        return wordBreak(s,wordDict,0);
    }
    

    //memoization solution
    Map<Integer,Boolean> memo = new HashMap<>();
    boolean wordBreak(String s , List<String> word , int pos){
        if(pos == s.length()) return true;
        if(memo.containsKey(pos)) return memo.get(pos);
        for(int i = pos; i<s.length();i++){
           if(word.contains(s.substring(pos,i+1))  && wordBreak(s,word,i+1)){
                memo.put(pos,true);
                return true;
            }
        }
        
        memo.put(pos,false);
        return false;
    }
}