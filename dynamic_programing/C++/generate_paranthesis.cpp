// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// n = 3
// ["((()))","(()())","(())()","()(())","()()()"]

#include <bits/stdc++.h>
using namespace std;

void solve(string& s, int open, int close, vector<string>& res){
    if(open == 0 and close == 0){
        res.push_back(s);
        return;
    }

    if(open < close) return;

    if(open > 0){
        string opt1 = s + ")";
        solve(opt1, open-1, close, res);
    }
    if(close > 0){
        string opt2 = s + "(";
        solve(opt2, open, close-1, res);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string temp = "";
    solve(temp, n, n, res);
    return res;
}
