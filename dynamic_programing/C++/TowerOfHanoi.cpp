/*
The Tower of Hanoi game consists of three stacks (left, middle and right) and n
n
 round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom. 

The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.

Your task is to find a solution that minimizes the number of moves.

Input

The only input line has an integer n
n
: the number of disks.

Output

First print an integer k
k
: the minimum number of moves.

After this, print k
k
 lines that describe the moves. Each line has two integers a
a
 and b
b
: you move a disk from stack a
a
 to stack b
b
.

Constraints
1≤n≤16

Example

Input:
2

Output:
3
1 2
1 3
2 3
*/

// Solution
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
void shift(int n, int a, int b, int c)
{

    if (n > 0)
    {
        shift(n - 1, a, c, b);
        cout << a << " " << c << endl;
        shift(n - 1, b, a, c);
    }
}
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << ((int)pow(2, n) - 1) << endl;
    }
    shift(n, 1, 2, 3);

    return 0;
}