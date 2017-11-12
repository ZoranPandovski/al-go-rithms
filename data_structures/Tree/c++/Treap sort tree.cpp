#include<bits/stdc++.h>

typedef long long LL;  
using namespace std;

#define fillchar(a, x) memset(a, x, sizeof(a))
#define MP make_pair
#define PB push_back
#define endl '\n'

const int M = (int)1e9+7;

//Treap sort tree
//--assuming all elements distinct

struct node
 {
    int key;
    int pr;
    int sz;
    node* l;
    node* r;

    node(int _key)
    {
        key = _key;
        pr = rand();
        l = NULL;
        r = NULL;
        sz = 1;

    }
};


 int size(node* t)
{
    return t?t->sz:0;
}

void upd_sz(node *t)
{
   if(t) 
	t->sz = size(t->l)+ size(t->r) + 1;
}

struct Treap
  { 
    node* root;

    Treap()
    {
        root = NULL;
        srand(time(NULL));
    }

    /* split t and return l and r as the two parts */
    void split(node* t,node* &l,node* &r,int key)     
    {      
        if(t==NULL) 
            {l = NULL;r = NULL;}
		else if(key >= t->key)
            {split(t->r,t->r,r,key); l = t;}
        else
            {split(t->l,l,t->l,key); r = t;}

        upd_sz(t);
    }

     /* merge l and r and make it t */
    void merge(node* &t,node* l,node* r) 
    {   
        if(l==NULL || r==NULL) 
            t=(l ? l : r);
        else if(l->pr > r->pr)
            {merge(l->r,l->r,r); t = l;}
        else
            {merge(r->l,l,r->l); t = r;}    

        upd_sz(t);      
    }

    /*insert node it into tree t and return new tree root through t*/
    void add(node* &t,node* it)
    {

        if(!t){
            t=it;
            }
        else if(t->pr < it->pr)
            {split(t,it->l,it->r,it->key); t = it;
			}
        else
            {
               if(t->key >= it->key) 
                    add(t->l,it);
                else
                    add(t->r,it);
            }
        upd_sz(t);    
    }

    /* erasing a node from tree t with value key and return the root through t*/
    void erase(node* &t,int key)
    {
        if(t==NULL) {
            return;
        }

        if(t->key < key) erase(t->r,key); 
        else if(t->key > key) erase(t->l,key);
        else { node* tmp = t; merge(t,t->l,t->r); free(tmp); }
        upd_sz(t);
    }

    //0 indexed 
    int get_id(node* nd,int key)
    {
    	if(!nd) return -M;
    	if(nd->key < key)
    		{	
    			return size(nd->l)+1+get_id(nd->r,key);
    		}	
    	else if(nd->key > key)
    		return get_id(nd->l,key);
    	else 
    		return size(nd->l);
    }


    void print(node* nd)
    {
    	if(nd == NULL)
    		return;

    	print(nd->l);
    	cout<<nd->key<<' ';
    	print(nd->r);

    }

  };

const int N = 2e5;
Treap tree[4*N];
 
void build(int x,int l,int r)
{	int m= (l+r) >> 1;

	if(l<r)
	{
		build(2*x,l,m);
		build(2*x+1,m+1,r);
		for(int i=l;i<=r;i++)
			tree[x].add(tree[x].root,new node(i));
	}
	else
 		tree[x].add(tree[x].root,new node(l));
}
 

int getS(int x,int l,int r,int ll,int rr,int k)
{
	int m= (l+r) >> 1;
 
	if (ll<=l && r<=rr)
		 return tree[x].get_id(tree[x].root,k)-1; //how many smaller
	 else if (r<ll || l>rr)
		return 0;
	else
		return getS(2*x,l,m,ll,rr,k) + getS(2*x+1,m+1,r,ll,rr,k);
}

void updateR(int x,int l,int r,int loc,int data)
{
	int m;
	if (l<=loc &&  loc<=r  && l<r)  
	{
		m=(l+r) >> 1;

		updateR(2*x,l,m,loc,data);
		updateR(2*x+1,m+1,r,loc,data);

		tree[x].erase(tree[x].root,data);
	}
	else if(l==r && l==loc)
	{
		tree[x].erase(tree[x].root,data);
	}
}


void updateA(int x,int l,int r,int loc,int data)
{
	int m;
	if (l<=loc &&  loc<=r  && l<r)  
	{
		m=(l+r) >> 1;

		updateA(2*x,l,m,loc,data);
		updateA(2*x+1,m+1,r,loc,data);

		tree[x].add(tree[x].root,new node(data));
	}
	else if(l==r && l==loc)
	{
		tree[x].add(tree[x].root,new node(data));
	}
}



int main()
{
	
	int n,q;
	LL cur = 0;
	cin >> n >> q;
	build(1,0,n-1);

	vector <int> v(n);

	for(int i=0;i<n;i++)
		v[i] = i;

	while(q--)
	{
		int a,b;
		cin >> a >> b;
		if(a==b) 
			{cout<<cur<<endl; continue;}
		if(a>b) swap(a,b);
		a--;b--;
		int a1 = getS(1,0,n-1,a+1,b-1,v[b]);
		int a2 = getS(1,0,n-1,a+1,b-1,v[a]);
		cur = cur + a1 - (b-a-1-a1);
		cur = cur - a2 + (b-a-1-a2);
		cur += (v[a] < v[b] ? 1 : -1);
		swap(v[a],v[b]);
		updateR(1,0,n-1,a,v[b]);
		updateA(1,0,n-1,a,v[a]);
		updateR(1,0,n-1,b,v[a]);
		updateA(1,0,n-1,b,v[b]);

		cout << cur << endl;
	}	

}
