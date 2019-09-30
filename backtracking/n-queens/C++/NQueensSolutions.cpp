/*
format for testing: 
<number of test cases t>
<t lines containing an integer(number of queens/board_size) between 1 & 1000>
 sample test case is :  
5
4
2
8
10
9
*/


#include<bits/stdc++.h>
using namespace std;
bool chess[1001][1001];
vector<int>v;
int N,solutions=0;
bool colOK(int a, int b){   // checking if column is safe
    while(a){
        if(chess[a][b]){
            return false; 
        } 
        a--;
    }
    return true;
}

bool d1OK(int a, int b){    // checking if left diagonal is safe
    while(a && b){
        if(chess[a][b]){ 
            return false;
        } 
        a--;
        b--;
    }
    return true;
}
bool d2OK(int a, int b){    // checking if right diagonal is safe
    while(a && b<=N){
        if(chess[a][b]){ 
            return false;
        } 
        a--;
        b++;
    }
    return true;
}


bool isOK(int a, int b){    // checking if box is safe
    if(colOK(a,b) && d1OK(a,b) && d2OK(a,b)){
        return true;
    }
    return false;
}
void solve(int row, int n){
    if(n==0){       // if a solution is found print it
        solutions++;
        cout<<"[";
        for(auto x:v) cout<<x<<" ";
        cout<<"] ";
    }
    for(int col=1; col<=N; col++){
        if(isOK(row,col)){
            chess[row][col]=1;
            v.push_back(col);
            solve(row+1,n-1);   // recursively finds a solution to the remaining board
        }
    }
    chess[row-1][v.back()]=0;   // backtrack and unset the previous placed queen
    v.pop_back();   // remove column from solution
}

void initBoard(){
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            chess[i][j]=0;
        }
    }
}
int main(){
    int t;
    cin>>t;     // give number of test cases to solve
    while(t--){
        cin>>N;     // enter a test case
        initBoard();    // initialise the board to empty
        v.clear();  // reset the solution vector
        solutions=0;
        solve(1,N);
        if(!solutions) cout<<"-1";  // print -1 if no solutions exist
        cout<<"\n";
    }
}