#include<string>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int minsize=INT_MAX;
        
        for(auto ind:strs)
        {
            minsize=min(minsize,int(ind.size()));
        }
        
        int j=0;
        
        for(j=0;j<minsize;j++)
        {
            bool flag=0;
            for(int ind=0;ind<strs.size()-1;ind++)
            {
                if(strs[ind][j]!=strs[ind+1][j])
                {
                    flag=1;
                    break;
                }
            }
            
            if(flag)
            {
                break;
            }
        }
        
        return strs[0].substr(0,j);
    }
};

/*
Input: strs = ["flower","flow","flight"]
Output: "fl"
*/