#include <bits/stdc++.h>
#define int long long
#define float double
#define endl "\n"
#define forp(i, x, t) for (int i = x; i < t; i++)
#define forn(i, t) for (int i = t; i >= 0; i--)
#define veci vector<int>
#define pb(x) push_back(x)
const int mod = 1e9 + 7;
 
using namespace std;
 
bool possible(vector<vector<int>> board, int r, int c){
    forp(i,0,c) if (board[r][i] == 1) return false;
 
    for (int i=r, j = c; i>=0 && j>=0; i--, j--){
        if (board[i][j] == 1) return false;
    }
 
    for (int i=r, j = c; i<8 && j>=0; i++,j--){
        if (board[i][j] == 1) return false;
    }
 
    return true;
}
 
bool solve(vector<vector<int>> board, int col, int* count){
    if (col == 8) {(*count)++; return true;}
 
    bool res = false;
    forp(i,0,8){
        if (board[i][col] != -1 && possible(board, i , col)){
            board[i][col] = 1;
 
            res = solve(board, col+1, count) || res;
 
            board[i][col] = 0;
        }
    }
 
    return false;
}
 
int32_t main(){
 
    int count = 0;
    vector<vector<int>> board(8, vector<int>(8, 0));
 
    forp(i,0,8){
        forp(j,0,8){
            char c;
            cin >> c;
            if (c == '*') board[i][j] = -1;
        }
    }
 
    solve(board, 0, &count);
 
    cout << count << endl;
    return 0;
}