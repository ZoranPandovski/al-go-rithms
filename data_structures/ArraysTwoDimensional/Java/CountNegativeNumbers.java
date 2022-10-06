class Solution {
    public int countNegatives(int[][] grid) {
        int rows = grid.length;
        int columns = grid[0].length;
        int rp = 0;
        int cp = columns -1;
        int count=0;
        while(cp>=0 && rp<rows)
        {
            if(grid[rp][cp]<0)
            {
                count+=(rows-rp);
                cp--;
            }
            else
            {
                rp++;
            }
            
        }
        return count;
        
    }
}
