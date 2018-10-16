#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int n;
int w;

int KnapSack(int g[],int h[])
{
	int V[n+1][w+1];
	int k[n+1][w+1];

	int i,j;

	for(i=0;i<=w;i++)
		V[0][i]=0;
	
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			if(h[i] < j && (g[i]+V[i-1][j-h[i]]) > V[i-1][j])
			{
				k[i][j]=1;
				V[i][j]= g[i]+ V[i-1][j-h[i]];
			}
			else
			{
				k[i][j]=0;
				V[i][j]= V[i-1][j];
			}

		}
	}

	printf("Ideal subset: \n");
	j=w;

	for(i=n;i>=1;i--)
	{
		if(k[i][j]==1)
		{	
			printf("%d\t",i );
			j=j-h[i];
		}
	}
	printf("\n");

	printf("Optimal Value: %d\n",V[n][w]);
}

void main()
{
	printf("enter number of elements:\n");
	scanf("%d",&n);
	printf("enter capacity of KnapSack:\n");
	scanf("%d",&w);

	int i=0;
	int g[n+1],h[n+1];

	for(i=1;i<=n;i++)
	{
		printf("enter weight and value of %d\n",i);
		scanf("%d %d", &h[i],&g[i]);
	}

	KnapSack(g,h);
}