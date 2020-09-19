#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct subarr
{
    ll best, pre, suff, total;
}tree[400005];
void build(ll node, ll l, ll r, ll a[])
{
    if(l > r)
        return;
    if(l == r)
    {
        tree[node].pre = tree[node].suff = tree[node].total = tree[node].best = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    ll li = 2 * node + 1;
    ll ri = 2 * node + 2;
    build(li, l, mid, a);
    build(ri, mid + 1, r, a);
    tree[node].pre = max(tree[li].pre, tree[li].total + tree[ri].pre);
    tree[node].suff = max(tree[ri].suff, tree[li].suff + tree[ri].total);
    tree[node].total = tree[li].total + tree[ri].total;
    tree[node].best = max(tree[li].suff + tree[ri].pre, max(tree[li].best, tree[ri].best));
}
subarr query(ll node, ll l, ll r, ll a, ll b)
{
    subarr t;
    if(a > b || l > b || r < a)
    {
        t.pre = t.best = t.suff = INT_MIN;
        t.total = 0;
        return t;
    }
    if(l <= a && r >= b)
        return tree[node];
    ll mid = (a + b) >> 1;
    ll li = 2 * node + 1;
    ll ri = 2 * node + 2;
    subarr left = query(li, l, r, a, mid);
    subarr right = query(ri, l, r, mid + 1, b);
    t.pre = max(left.pre, left.total + right.pre);
    t.suff = max(right.suff, right.total + left.suff);
    t.total = left.total + right.total;
    t.best = max(left.suff + right.pre, max(left.best, right.best));
    return t;
}
int main()
{
    ll n, m, i, l, r, y, x;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    ll a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];
    build(0, 0, n - 1, a);
    cin >> m;
    while(m--)
    {
        cin >> x >> y;
        subarr ans = query(0, x - 1, y - 1, 0, n - 1);
        cout << ans.best << endl;
    }
    return 0;
}
