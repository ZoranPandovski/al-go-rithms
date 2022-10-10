/*
  Problem statement: Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
  
  Test cases:
  
  1.
  Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
  Output: 6
  
  2.
  Input: matrix = [["0"]]
  Output: 0
  
  3.
  Input: matrix = [["1"]]
  Output: 1


*/
class pair{
    int e;
    int ind;
    pair(int e, int ind){
        this.e = e;
        this.ind = ind;
    }
}
class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<pair> st = new Stack<>();
        int[] rg = new int[heights.length];
        rg[heights.length-1] = heights.length; // assume small on right
        st.push(new pair(heights[heights.length-1],heights.length-1));
        for(int i=heights.length-2;i>=0;i--){
            while(st.size()>0 && st.peek().e>=heights[i]){
                st.pop();
            }
            if(st.size()==0){
                rg[i] = heights.length;
            }else{
                rg[i] = st.peek().ind;
                
            }
            st.push(new pair(heights[i],i));
        }
        while(st.size()>0){
            st.pop();
        }
        int[] lg = new int[heights.length];
        lg[0] = -1;
        st.push(new pair(heights[0],0));
        for(int i=1;i<heights.length;i++){
            while(st.size()>0 && st.peek().e>=heights[i]){
                st.pop();
            }
            if(st.size()==0){
                lg[i] = -1;
            }else{
                lg[i] = st.peek().ind;
                
            }
            st.push(new pair(heights[i],i));
        }
        
        int ans = 0;
        for(int i=0;i<heights.length;i++){
            int b = Math.abs(rg[i]-lg[i]-1);
            ans = Math.max(ans,b*heights[i]);
        }
        return ans;
        
    }
    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        
        int[] a = new int[n];
        int ans = Integer.MIN_VALUE;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!='0'){
                    a[j]+=(matrix[i][j]-'0');
                }else{
                    a[j] = 0;
                }
            }
            
            ans = Math.max(ans,largestRectangleArea(a));
        }
        
        return ans;
    }
}
