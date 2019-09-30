/*
    n : order of square
    Magic Square : In any magic square, the first number i.e 1 is stored at position (n/2, n - 1);
    let this position be (i, j), the next number is stored at (i - 1, j + 1) where we can assume each row & column as circular array
    i.e they wrap around.

    Conditions:
    1 -   The position of next is calculated by decrementing the row number no of previous number by 1.
          If the calculated row position becomes -1, it will wrap around to n - 1. Similarly, if column position
          becomes n, it will wrap around to 0.

    2 -   If the magic square already contains a number at calculated position, calculated column position will be decremented
          by 2 and calculated row position will be incremented by 1.

    3 -   If calculated row position is -1 & calculated column position is n, new position will be (0, n - 2).

calculate magic square number : n (n ^ 2 + 1)/2

*/



#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>

using namespace std;
typedef long long int lint;

void createSquare(int N) {
    int A[N][N];
    for (int i  = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = 0;
        }
    }
    int i = N/2, j = N - 1;
    for (int k = 1; k <= N * N; ) {
        if (i == -1 && j == N) {
            j = N - 2;
            i = 0;
        } else {
            if (j == N) {
                j = 0;
            }
            if (i < 0) {
                i = N - 1;
            }
        }
        if (A[i][j]) {
            j -= 2;
            i += 1;
            continue;
        } else {
            A[i][j] = k++;
        }
        j += 1;
        i -= 1;
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    createSquare(N);
    cout << "Magic number : " << N * (N*N + 1)/2 << endl;
    return 0;
}
