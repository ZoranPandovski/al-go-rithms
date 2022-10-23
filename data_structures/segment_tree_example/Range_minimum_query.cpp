#include <bits/stdc++.h>
#define present(container, element) (container.find(element) != container.end()
#define all(c) c.begin(), c.end()
#define lli long long int
#define vi vector<int>
#define cpresent(container, element) (find(all(container),element) != container.end())
#define tr(container, it) for(auto it = container.begin(); it != container.end(); it++)
using namespace std;

// This segment tree can be used to find the minimum in a range [L,....,R)

// This template also supports update on the tree

struct segtree{
    int size;
    vector<lli> st;

    // Here we are initializing our data structure

    void init(int n) {
        size=1;
        while(size<n) size*=2;
        st.assign(2*size, 1e14);
    }

    // we are building the tree with the values of the given array

    void buildTree(vector<int> &a, int si, int lx, int rx){
        if(rx - lx == 1){
            if(lx<(int)a.size()){
                st[si] = a[lx];
            }
            return;
        }
        int m = (lx+rx)/2;
        buildTree(a, 2*si+1, lx, m);
        buildTree(a, 2*si+2, m, rx);
        st[si] = min(st[2*si+1],st[2*si+2]);
    }

    void build(vector<int> &a){
        buildTree(a, 0, 0, size);
    }

    void set(int i, int v, int si, int lx, int rx){
        if(rx - lx == 1){
            st[si] = v;
            return;
        }

        int m = (lx+rx)/2;
        if(i<m) {
            set(i, v, 2*si+1, lx, m);
        } else {
            set(i, v, 2*si+2, m, rx);
        }
        st[si] = min(st[2*si+1], st[2*si+2]);
    }

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    lli minS(int l, int r, int si, int lx, int rx){
        if(lx>=r || l>=rx) return 1e14;
        if(lx>=l && rx<=r) return st[si];
        int m = (lx+rx)/2;
        lli s1 = minS(l, r, 2*si+1, lx, m);
        lli s2 = minS(l, r, 2*si+2, m, rx);
        return min(s1,s2);
    }

    lli getMin(int l, int r) {
        return minS(l, r, 0, 0, size);
    }

};



int main()
{
ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
segtree st;
int n, m;

cin>>n>>m;
st.init(n);
vector<int> a(n);
for(int i=0;i<n;i++) cin>>a[i];
st.build(a);
int c, x, y;
while(m--)
{
    cin>>c>>x>>y;
    if(c==1){
        st.set(x, y);
    } else {
        cout<<st.getMin(x, y)<<endl;
    }
}

return 0;
}
