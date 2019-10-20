#include <bits/stdc++.h>

using namespace std;

double mat[105][105];
int r,c;

// get the leftest one in row a
int findPivot(int a) {
    for (int i=1;i<c;i++) {
        if (abs(mat[a][i]-1) <= 0.0001) return i;
    }
    return -1;
}

// swap row a and b
void swapRows(int a, int b) {
    for (int i=1;i<=c;i++) {
        mat[0][i] = mat[a][i];
        mat[a][i] = mat[b][i];
        mat[b][i] = mat[0][i];
    }
}

// multiply row a with a number x
void multiplyRow(int a, double x) {
    for (int i=1;i<=c;i++) {
        mat[a][i] = mat[a][i] * x;
    }
}

// add row a with row b multiplied by x
void addRow(int a,int b, double x) {
    for (int i=1;i<=c;i++) {
        mat[a][i] = mat[a][i] + mat[b][i] * x;
    }
}

// turn matrix into its echelon form
void EchelonForm() {
    int move = 0;
    for (int i=1;i<=c;i++) {
        if (mat[i][i + move] == 0) {
            bool tuker = false;
            for (int j=i+1;j<=c;j++) {
                if (mat[j][i] != 0) {
                    swapRows(i, j);
                    tuker = true;
                    break;
                }
            }
            if (tuker == false) {
                move++;
                i--;
                continue;
            }
        }
        multiplyRow(i, 1/mat[i][i + move]);
        for (int j=i+1;j<=c;j++) {
            addRow(j, i, -1 * mat[j][i + move] / mat[i][i + move]);
        }
    }
    for (int i=1;i<=c;i++) {
        int p=0;
        for (int j=1;j<=c;j++) {
            if (mat[i][j] != 0) {
                p = j;
                break;
            }
        }
        if (p == c-1) {
            multiplyRow(i, 1/mat[i][p]);
        }
    }
}

// turn matrix into its reduced echelon form
void ReducedEchelonForm() {
    EchelonForm();
    for (int i=c;i>=1;i--) {
        int pivot = findPivot(i);
        if (pivot == -1) continue;
        for (int j=i-1;j>=1;j--) {
            addRow(j, i, -1 * mat[j][pivot]);
        }
    }
}

int main () {
    cout << "Input number of rows: ";
    cin >> r;
    cout << "Input number of columns: ";
    cin >> c;
    cout << "Input the matrix, seperated with spaces" << endl;
    // input matrix
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            cin >> mat[i][j];
        }
    }
    ReducedEchelonForm();
    // output matrix
    cout << "Matrix after Gauss-Jordan Elimination" << endl;
    for (int i=1;i<=r;i++) {
        for (int j=1;j<=c;j++) {
            if (mat[i][j] == 0) mat[i][j] = 0;  // getting rid of negative 0
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}