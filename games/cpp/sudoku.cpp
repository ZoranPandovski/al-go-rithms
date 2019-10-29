//Implement sudoku solver using recursion (Conceptual)
#include<iostream>
using namespace std;
bool isPossible(int sudoku[][9], int i, int j, int k){
    //i=row, j=col, k=value
    //check if value k is present in row or col
    for(int p=0;p<9;p++){
        if(sudoku[p][j]==k || sudoku[i][p]==k)
            return false;
    }
    //check in sub-sudoku
        //Find the starting index of the sub-sudoku for (i,j) (IMPORTANT)
    int si=(i/3)*3;
    int sj=(j/3)*3;
    for(int p=si;p<si+3;p++){
        for(int q=sj;q<sj+3;q++)
            if(sudoku[p][q]==k)
                return false;
    }
    return true;
}

bool sudokuSolver(int sudoku[][9], int i, int j){
    //base case
    if(i==9){
        //print soduko
        for(int p=0;p<9;p++){
            for(int q=0;q<9;q++)
                cout<<sudoku[p][q]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    //edge cases
        //if j>9 and (i,j) value already fixed
    if(j>=9)
        return sudokuSolver(sudoku,i+1,0);
    if(sudoku[i][j]!=0)
        return sudokuSolver(sudoku,i,j+1);
    
    //recursive cases
    for(int k=1;k<=9;k++){
        if(isPossible(sudoku,i,j,k)){
            sudoku[i][j]=k;
            bool solved = sudokuSolver(sudoku,i,j+1);
            if(solved)
                return true;
        }
    }
    //backtrack
    sudoku[i][j]=0;
    return false;
}
int main(){
    int sudoku[9][9]={
                {3, 0, 6, 5, 0, 8, 4, 0, 0},  
                {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                {0, 0, 5, 2, 0, 6, 3, 0, 0}  
            };
    sudokuSolver(sudoku,0,0);
    return 0;
}