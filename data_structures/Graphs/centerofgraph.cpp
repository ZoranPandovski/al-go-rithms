//1791. Find Center of Star Graph

// O(1) time complexity 

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
     if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1])
     {
         return edges[0][0];
     }
     else {
         return edges[0][1];
     }
     
    }
};
