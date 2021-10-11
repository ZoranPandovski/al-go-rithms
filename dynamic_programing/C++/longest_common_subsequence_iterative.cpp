#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int dfs(string& text1, string& text2, int pos1, int pos2){
    if(pos1 == text1.length() or pos2 == text2.length())
        return 0;

    if(dp[pos1][pos2] != -1)
        return dp[pos1][pos2];

    if(text1[pos1] == text2[pos2])
        return  dp[pos1][pos2] = 1 + dfs(text1, text2, pos1+1, pos2+1);

    return  dp[pos1][pos2] = max(
        dfs(text1, text2, pos1+1, pos2), 
        dfs(text1, text2, pos1, pos2+1)
    );
}

int longestCommonSubsequence(string text1, string text2) {
    dp.resize(text1.length()+1, vector<int>(text2.length()+1, -1));
    return dfs(text1, text2, 0, 0);
}
