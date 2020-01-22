class Solution {
    public void reverseString(char[] s) {
        if(s.length>1){
            int first = 0;
            int temp;
            
            for (int i = s.length-1; i>=s.length/2; i--){
                temp = s[first];
                s[first] = s[i];
                s[i] = (char) temp;
                first++;
            }
        }
    }
}
