#include <bits/stdc++.h>
using namespace std;
#define For(j, i, f) for (int j = i; j <= f; j++)
#define lli long long int
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vb vector<bool>
#define vs vector<string>
#define vc vector<char>
#define pb push_back
#define foreach(x, arr) for (auto x : arr)
#define all(x) (x).begin(), (x).end()
#define PQi priority_queue<int, vector<int>>
#define inputArr(arr, n) For(i, 0, n - 1) cin >> arr[i];

// ====================  SEGMENT TREE ================

// It can be used for range queries in an array

// Here we are creating a segment tree for finding the maximum element in a range of an array

int n;
vector<int> seg;

void buildTree(vector<int> &arr, int ind, int l, int r)
{
    if (l == r)
    {
        seg[ind] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    buildTree(arr, 2 * ind + 1, l, mid);
    buildTree(arr, 2 * ind + 2, mid + 1, r);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int query(int ind, int l, int r, int L, int R)
{
    if (l >= L && r <= R) //Current node's range lies completely within given query range
        return seg[ind];
    if (l > R || r < L)  //Current node's range lies completely outside given query range
        return INT_MIN;
    int mid = (l + r) / 2;
    int left = query(2 * ind + 1, l, mid, L, R);
    int right = query(2 * ind + 2, mid + 1, r, L, R);
    return left + right;
}

// This update() will increase the specified position element by the value given by user.
void update(int ind, int l, int r, int pos, int val)
{
    if (pos < l || pos > r)
        return;
    // We will only be traversing through a single defined path as we are also
    // folling the condition of position.
    if (l == r) // If leaf node, it will surely be the node we need.
    {
        seg[ind] += val; // Incrementing the value of the element
        return;
    }
    int mid = (l + r) / 2;
    update(2 * ind + 1, l, mid, pos, val);
    update(2 * ind + 2, mid + 1, r, pos, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

// This rangeUpdate() will increase the value of elements in the given range by
// the value specified by user.

// ================ Normal method of range update ====================
// This is not the efficient approach for updating a range of elements.
// Most efficient approach is Lazy Propagation.
// It will be discussed in the next file.

void rangeUpdate(int ind, int l, int r, int st, int en, int val)
{
    if (st > r || en < l)
        return;
    if (l == r) // If leaf node, it will surely be a node in the specified range.
    {
        seg[ind] += val; // Incrementing the value of the element
        return;
    }
    int mid = (l + r) / 2;
    rangeUpdate(2 * ind + 1, l, mid, st, en, val);
    rangeUpdate(2 * ind + 2, mid + 1, r, st, en, val);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int doQuery(int l, int r)
{
    return query(0, 0, n - 1, l, r);
}

void doUpdate(int pos, int val)
{
    update(0, 0, n - 1, pos, val);
}

void doRangeUpdate(int st, int en, int val)
{
    rangeUpdate(0, 0, n - 1, st, en, val);
}

int main()
{
    vector<int> arr = {2, 4, 6, 7, 2, 8, 9, 3, 8};
    n = arr.size();
    seg.resize(4 * n);
    buildTree(arr, 0, 0, n - 1);
    int l = 2, r = 6; // indices
    cout << "Sum of elements between " << l << " and " << r << " = " << doQuery(l, r) << endl;
    doUpdate(4, 11);
    cout << "Sum of elements between " << l << " and " << r << " = " << doQuery(l, r) << endl;
    doUpdate(6, 18);
    cout << "Sum of elements between " << l << " and " << r << " = " << doQuery(l, r) << endl;
    doRangeUpdate(2, 6, 9);
    cout << "Sum of elements between " << l << " and " << r << " = " << doQuery(l, r) << endl;
    return 0;
}