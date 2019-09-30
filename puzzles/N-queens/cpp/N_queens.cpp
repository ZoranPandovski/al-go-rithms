#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>


using namespace std;

typedef long long int lint;

int totalcalls = 0;
int c = 0;

bool isSafe(vector<vector <int> > &board, int i, int j, int N) {
    for (int row = 0; row < i; ++row) {
        if (board[row][j] == 1) {
            return false;
        }
    }
    // check for left upper diagonal
    int x = i, y = j;
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        --x;
        --y;
    }
    // check for right upper diagonal
    x = i, y = j;
    while (x >= 0 && y < N) {
        if (board[x][y] == 1) {
            return false;
        }
        --x;
        ++y;
    }
    // so, position is safe for queen.
    return true;
}

void printBoard(vector<vector <int> > &board, int N) {
    c++;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1) {
                cout << "Q";
            } else {
                cout << "_ ";
            }
        }
        cout << endl;
    }
}

bool solveNqueen(vector<vector <int> > &board, int i, int N) {
    totalcalls++;
    // Base case
    if (i == N) {
        // print the board.
        printBoard(board, N);
        cout << endl << endl;
        return false;          // for one sol.return true else return false for printing all the possible solutions.
    }
    for (int j = 0; j < N; ++j) {
        if (isSafe(board, i, j, N)) {
            board[i][j] = 1;        // place the queen assuming i-j th is right position.

            bool nextQueen = solveNqueen(board, i + 1, N);
            if (nextQueen) {
                return true;
            }
            // if i-j th position is not right - assumption is wrong
            board[i][j] = 0;        // backtrack.. unchoose
        }
    }
    // couldn't place queen.
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<vector <int> >board(N, vector<int>(N, 0));
    solveNqueen(board, 0, N);
    cout << "totalcalls : " << totalcalls << endl;
    cout << "total solutions: " << c << endl;
    return 0;
}
