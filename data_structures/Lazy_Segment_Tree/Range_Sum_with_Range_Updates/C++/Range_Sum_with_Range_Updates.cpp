
/*

C++ Implementation of Lazy Segment Tree for range sum query with range addition.
Initially you will be given an array and then you will be given queries of two types :-
 1) l r (In this type of query you have to find sum over range l to r in array)
 2) l r x (In this type of query you have to add value x over range l to r in array)

TestCases 
   Input :- 
   5 2
   1 20 4 6 20
   2 1 3 -4
   1 1 3

   Output :-
   18


Time Complexity :-
   Each sum query takes O(log(n)) time
   Each update query takes O(log(n)) time
   Time to build LazySegtree takes O(nlog(n)) time

   Here n is the number of elements in the array

*/

#include <bits/stdc++.h>
using namespace std;

//Class implementation of Lazy Segment Tree
class LazySegTree {
    vector<int>tree,lazy;
public:
    LazySegTree(){}

    LazySegTree(vector<int>&a) {
        int n = a.size();
        tree.resize(4*n);
        lazy.resize(4*n);
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
        tree[node] = tree[2*node] + tree[2*node+1];
    }
    
    //Update function to update the tree while adding x to array over range l to r
    void update(int l,int r,int x,int st,int en,int node) {
        int mid = (st+en)/2;
        if(lazy[node] and st!=en) {
            tree[2*node] += (mid-st+1)*lazy[node];
            tree[2*node+1] += (en-mid)*lazy[node];
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
            lazy[node] = 0;
        }
        if(st > r or en < l) return;
        if(st >= l and en <= r) {
            tree[node] += (en-st+1)*x;
            lazy[node] += x;
            return;
        }
        update(l,r,x,st,mid,2*node);
        update(l,r,x,mid+1,en,2*node+1);
        tree[node] = tree[2*node]+tree[2*node+1];
    }
    
    //query function return sum over range l to r
    int query(int l,int r,int st,int en,int node) {
        int mid = (st+en)/2;
        if(lazy[node] and st!=en) {
            tree[2*node] += (mid-st+1)*lazy[node];
            tree[2*node+1] += (en-mid)*lazy[node];
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
            lazy[node] = 0;
        }
        if(st > r or en < l) return 0;
        if(st >= l and en <= r) return tree[node];
        return query(l,r,st,mid,2*node)+query(l,r,mid+1,en,2*node+1);
    }
};

int main() {
    int n,q;
    //n is number of elements in array
    //q is the number of queries

    cin>>n>>q;

    vector<int>a(n);
    //Input the array a
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    LazySegTree tr(a);

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
            int l,r,x;
            cin>>l>>r>>x;
            //Add value x over range l to r to the array a
            tr.update(l,r,x,0,n-1,1);
        }
    }

    return 0;
}