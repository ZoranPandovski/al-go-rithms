/*
Problem: Given a binary matrix, find out the maximum size square sub-matrix with all 1s.
link: https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/

Test case 1: consider the below 6x5 binary matrix:

{0, 1, 1, 0, 1}
{1, 1, 0, 1, 0}
{0, 1, 1, 1, 0}
{1, 1, 1, 1, 0}
{1, 1, 1, 1, 1}
{0, 0, 0, 0, 0}

Output: 9

Explaination:
Largest square matrix possible is
1 1 1
1 1 1
1 1 1
here side is 3 units hence area = 9.

Solution:
*/

#include<bits/stdc++.h>
using namespace std;


int maxSquare(int n, int m, vector<vector<int>> mat){
    int dp[n][m]={{0}};
    int maxi=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||j==0){
                dp[i][j]=mat[i][j];
            }
            else if(mat[i][j]==1){
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
            if(maxi<dp[i][j]){
                    maxi=dp[i][j];
            }
        }
    }
    return maxi*maxi;
}

int main(){
    int n,m;
    vector<vector<int>> mat={{0, 1, 1, 0, 1},{1, 1, 0, 1, 0},{0, 1, 1, 1, 0},{1, 1, 1, 1, 0},{1, 1, 1, 1, 1},{0, 0, 0, 0, 0}};
    n=mat.size();
    m=mat[0].size();
    cout<<maxSquare(n,m,mat);
}

