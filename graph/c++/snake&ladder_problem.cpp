/*
Problem statement :
    Given a snake and ladder board, find the minimum number of dice throws required to reach
    the destination or last cell from source or 1st cell.
    Basically, the player has total control over outcome of dice throw and wants to find out minimum number of throws
    required to reach last cell.
*/




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

void getMinThrows(vector <vector <int> > &A, int N, int *parent, int *temp) {
    queue <int> Q;
    vector<bool> visited(N, false);
    visited[1] = true;
    Q.push(1);
    while (!Q.empty()) {
        int z = Q.front();
        // cout << z << " -- " << parent[z] << " " << endl;
        Q.pop();
        vector<int> :: iterator i;
        for ( i = A[z].begin(); i != A[z].end(); ++i) {
            if (visited[*i] == false) {
                visited[*i] = true;
                Q.push(*i);
                temp[*i] = temp[z] + 1;
                parent[*i] = z;
            }
        }
    }
}


int printPath(int *parent, int current, int start) {
    static int count = 0;
    if (current == start) {
        cout << current << " ";
        count += 1;
    } else if (parent[current] == 0) {
        printPath(parent, start, start);
        cout << current << " ";
        count += 1;
    } else {
        printPath(parent, parent[current], start);
        cout << current << " ";
        count += 1;
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    vector <vector <int> > A(N + 1);
    int ladder, snake, u, v;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= 6 && i + j <= N; ++j) {
            A[i].push_back(i + j);
        }
    }
    cin >> ladder;
    for (int i = 0; i < ladder; ++i) {
        cin >> u >> v;
        for (int j = 1; j < N; ++j) {
            for (int k = 0; k < 6; ++k) {
                if (A[j][k] == u) {
                    A[j][k] = v;
                }
                A[u][k] = 0;
            }
        }
    }
    cin >> snake;
    for (int i = 0; i < snake; ++i) {
        cin >> u >> v;
        for (int j = 1; j < N; ++j) {
            for (int k = 0; k < 6; ++k) {
                if (A[j][k] == u) {
                    A[j][k] = v;
                }
                A[u][k] = 0;
            }
        }
    }
    int temp[N + 1], parent[N + 1];
    for (int i = 0; i <= N; ++i) {
        temp[i] = 0;
        parent[i] = 0;
    }

    // for (int i = 1; i < N; ++i) {
    //     cout << i << "--> ";
    //     for (int j = 0; j < A[i].size(); ++j) {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    getMinThrows(A, N, parent, temp);
    cout << "Path: ";
    int min_throws = printPath(parent, N, 1);
    cout << endl << min_throws - 1 << endl;
    return 0;
}
