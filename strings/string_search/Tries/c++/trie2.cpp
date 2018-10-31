#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define MAXM 26
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
			cout << (char)(i+'a') << " ";
			Display(root->ptr[i]);
			cout << "\n";
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
	}
	return 0;
}