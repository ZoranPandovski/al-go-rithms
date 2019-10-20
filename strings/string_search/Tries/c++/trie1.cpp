#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define MAXM 26

string path;
int p=0;

struct Node
{
	struct Node * ptr[MAXM];
	Node(){for(int i=0;i<MAXM;i++)ptr[i]=NULL;};
};

void insert(Node * root,char str[])
{
	if(root->ptr[str[0]-'a']==NULL)
		root->ptr[str[0]-'a']=new Node();
	if(str[1]!='\0')
		insert(root->ptr[str[0]-'a'],&str[1]);
	return ;
}

void Display(Node * root)
{
	for(int i=0;i<MAXM;i++)
	{
		if(root->ptr[i]!=NULL)
		{
			path=path+(char)(i+'a');
			cout << path;
			cout << "\n";
			Display(root->ptr[i]);
			p--;
			path[p]='\0';
		}
	}
}

int main()
{
	Node * root=new Node();
	string str;
	while(1)
	{
		cin >> str;
		if(str=="break")return 0;
		insert(root,&str[0]);
		Display(root);
		p=0;
		path="";
	}
	return 0;
}