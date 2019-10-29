//print all possible soln for a given rat-maze problem
#include<iostream>
using namespace std;
bool ratInMaze(char maze[][10], int out[][10], int m, int n, int i, int j){
    //base case
    if (i==m && j==n){
        //print the maze
        out[i][j]=1;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<out[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        //same reason as n-Queens (we need to print all soln; if only one make it return true)
        //return true

        //backtrack
        out[i][j]=0;
        return false;
    }

    //edge cases
    if(j>n || i>m){
        return false;
    }
    if(maze[i][j]=='X')
        return false;
    
    //recursive call
        //assume current block is possible
    out[i][j]=1;
    bool right = ratInMaze(maze,out,m,n,i,j+1);
    bool down = ratInMaze(maze,out,m,n,i+1,j);
    if(!right && !down){
        //assumption wrong, not possible ->backtrack
        out[i][j]=0;
        return false;
    }
    return true;
}
int main(){
    int m,n;
    //cin>>m>>n;
    char maze[10][10]={
                    "0000",
                    "00X0",
                    "0000",
                    "0X00"
                };
    int out [10][10]={0};
    ratInMaze(maze,out,4-1,4-1,0,0);
}