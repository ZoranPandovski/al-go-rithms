#include <stdio.h>
#include <limits.h>

int tree[100000];
int tree_size; 

int max(int a,int b)
{
	if (a>=b)
	return a;
	return b;
}

void heapify(int i)
{
	while(1)
	{
		if (i>=tree_size/2+1)
		{
			return ;
		}
		int lc = INT_MIN;
		int rc = INT_MIN;
		if (2*i<=tree_size) 
		{
			lc = max(lc,tree[2*i]);
		}
		if (2*i+1<=tree_size)
		{
			rc = max(rc,tree[2*i+1]);
		}
		int max_c = max(lc,rc);
		if (tree[i]>=max_c) 
			return ;
		if (lc==max_c)
		{
			int temp;
			temp=tree[2*i];
			tree[2*i]=tree[i];
			tree[i]=temp;
			i*=2;
			continue;
		}
		else 
		{
			int temp;
			temp=tree[2*i+1];
			tree[2*i+1]=tree[i];
			tree[i]=temp;
			i*=2; i++;
			continue;
		}
		
	}
}

void insert(int x)
{
	tree[++tree_size]=x;
	int i=tree_size;
	while(i>1)
	{
		if (tree[i/2]<tree[i])
		{
			int temp = tree[i/2];
			tree[i/2] = tree[i];
			tree[i] = temp;
		}
		else 
			break;
		i/=2;
	}
}

int main(void) {
	int n;
	scanf("%d",&n);
	tree_size=0;
	int i;
	for (i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		insert(temp);
	}
		
	for (i=1;i<=n;i++)
		printf("%d ",tree[i]);
	printf("\n");
	for (i=n/2;i>=1;i--)
	{
		heapify(i);
	}
	
	for (int i=1;i<=n;i++)
	{
		printf("%d ",tree[1]);
		tree[1]=tree[tree_size];
		tree_size--;
		heapify(1);
	}
		
	return 0;
}