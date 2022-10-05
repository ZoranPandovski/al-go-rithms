
/*

C++ Implementation of Segment Tree for range maximum query with updates.
Initially you will be given an array and then you will be given queries of two types :-
 1) l r (In this query you have to find maximum value over range l to r in array)
 2) pos val (In this type of query you have to update the value of array at position pos to val)


TestCases
Input :-

5 2
1 20 4 6 20
2 1 -4
1 1 3

Output :-
6

*/

#include <bits/stdc++.h>
using namespace std;

//Class implementation of Segment Tree
class SegmentTree{
    vector<int>tree;
    const int inf = 1e9;
    int n;
public:
    SegmentTree(){}

    SegmentTree(vector<int>a) {
        this->n = a.size();
        tree.resize(4*n);
        build(a,0,n-1,1);
    }

    //Build function to build tree over given array a
    void build(vector<int>&a,int st,int en,int node) {
        if(st == en) {
            tree[node] = a[st];
            return;
        }
        int mid = (st+en)/2;
        build(a,st,mid,2*node);
        build(a,mid+1,en,2*node+1);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
    
    //Update function to update the tree while update the value of array at index pos to val
    void update(int pos,int val,int st,int en,int node) {
        if(st > pos or en < pos) return;
        if(st == en) {
            tree[node] = val;
            return;
        } 
        int mid = (st+en)/2;
        update(pos,val,st,mid,2*node);
        update(pos,val,mid+1,en,2*node+1);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }

    int query(int l,int r,int st,int en,int node) {
        if(st > r or en < l) return -inf;
        if(st >= l and en <= r) return tree[node];
        int mid = (st+en)/2;
        return max(query(l,r,st,mid,2*node),query(l,r,mid+1,en,2*node+1));
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    
    int n,q;
    //n is number of elements in array
    //q is the number of queries

    cin>>n>>q;

    vector<int>a(n);
    //Input the array a
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    SegmentTree tr(a);

    while(q--) {
        int t;
        //t is type of query
        cin>>t;
        if(t == 1) {
            int l,r;
            //l, r is the range of the query to find maximum over array
            cin>>l>>r;
            cout<<tr.query(l,r,0,n-1,1)<<"\n";
        }
        else {
            int pos,val;
            cin>>pos>>val;
            //Update a[pos] = val;
            tr.update(pos,val,0,n-1,1);
        }
    }

    return 0;
}
