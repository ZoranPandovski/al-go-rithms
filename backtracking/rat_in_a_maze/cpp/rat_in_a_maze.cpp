
#include <iostream>
#define N 9
using namespace std;

int maze[N][N];
int path[N][N] = {0};
int direction[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
int src_x, src_y, dest_x, dest_y;

bool is_valid_move (int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0);
}

// this will not give the shortest path but only give one of the possible paths

bool traverse (int curr_x, int curr_y) {
    if (curr_x == dest_x && curr_y == dest_y)
        return true;
    for (int k = 0; k < 4; k++) {
        int next_x = curr_x + direction[k][0];
        int next_y = curr_y + direction[k][1];
        if (is_valid_move (next_x, next_y)) {
            maze[curr_x][curr_y] = 1;     // as the rat has already traversed this path marking it as a block to prevent rat from moving backwards
            path[next_x][next_y] = 1;
            if (traverse (next_x, next_y) == true)
                return true;
            else {
                maze[curr_x][curr_y] = 0;
                path[next_y][next_y] = 0;
            }
        }
    }
    return false;
}

int main() {
    cout << "Enter the maze (0 for empty, 1 for blocked square, 5 for source and 6 for destination) : \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 5) {
                src_x = i;
                src_y = j;
            }
            if (maze[i][j] == 6) {
                dest_x = i;
                dest_y = j;
            }
        }
    }
    path[src_x][src_y] = 1;
    maze[src_x][src_y] = 0;
    maze[dest_x][dest_y] = 0;
    if (! traverse (src_x, src_y)) {
        cout << "Sorry! The rat cannot reach the destination...";
        return 0;
    }
    cout << "The path followed by the rat to reach the destination is : \n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << path[i][j] << " ";
        cout << endl;
    }
    return 0;
}
