#include <bits/stdc++.h>
using namespace std;

long long mod = (int)1e9 + 7;

#define matrix2D vector<vector<long long>>

matrix2D matrixMultiply(matrix2D &a, matrix2D &b)
{
    matrix2D c(a.size(), vector<long long>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b[0].size(); j++)
        {
            for (int k = 0; k < a[0].size(); k++)
            {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return c;
}

matrix2D matrixPower(matrix2D &a, long long p)
{
    matrix2D res = matrix2D(a.size(), vector<long long>(a.size()));
    for (int i = 0; i < a.size(); i++)
        res[i][i] = 1;

    while (p)
    {
        if (p & 1)
            res = matrixMultiply(a, res);
        a = matrixMultiply(a, a);
        p >>= 1;
    }
    return res;
}

int main()
{
    matrix2D mat{{1, 1}, {1, 0}};
    mat = matrixPower(mat, 12);
    for (auto x : mat)
    {
        for (auto y : x)
            cout << y << " ";
        cout << "\n";
    }
}
