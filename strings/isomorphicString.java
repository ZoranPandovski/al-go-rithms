
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

class Solution {
    public boolean isIsomorphic(String s, String t) {
        
                
        HashMap<Character,Character> hm = new HashMap<Character,Character>();
        HashSet<Character> hs=new HashSet<Character>();
        for(int i=0;i<s.length();i++)
        {
          char ch1=s.charAt(i);
          char ch2=t.charAt(i);
          if(!hm.containsKey(ch1) && hs.contains(ch2))
              return false;
            else if(!hm.containsKey(ch1))
          {
             
              hm.put(ch1,ch2);
              hs.add(ch2);
          }
            else
            {
                
                if(hm.get(ch1) != ch2)
                    return false;
            }
        }
        return true;
    }
}
