#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define f first
#define s second
#define pii pair<int,int>
#define vii vector<pair<int,int> >
#define si stack<int>
#define ll long long int
#define MOD 1000000007

int maxi = 0;
// use this code only when only capital letters are there.

struct node
{
    struct node *children[40];
    int cou;
};

struct node *getNode(void)
{
    struct node *nod =  new struct node;

    int i;
    nod->cou = 0;

    for (i = 0; i < 40; i++)
        nod->children[i] = NULL;

    return nod;
}

void insert(struct node *root,string st)
{
    int level;
    int index;

    struct node *p = root;

    for (int i=0;i<st.size();i++)
    {
        index = st[i]-'A';
        if (!p->children[index])
            p->children[index] = getNode();
        p->children[index]->cou++;
        p = p->children[index];
    }
}

void print(struct node* root,int level){
    int f=0;
    for(int i=0;i<40;i++){
        if(root->children[i]!=NULL){
            f=1;
            //cout<<char(i+'A')<<" "<<root->children[i]->cou<<" -- ";
            int pp = root->children[i]->cou;

            print(root->children[i]);
        }
    }
    if(f==0)
        cout<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);

    #ifndef ONLINE_JUDGE
   	freopen("in.txt", "r", stdin);
    #endif

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        struct node *root = getNode();

        for(int j=0;j<n;j++){
            string st;
            cin>>st;
            insert(root,st);
        }
        print(root,0);
        cout<<"Case "<<i+1<<": "<<endl;
    }

    return 0;
}

