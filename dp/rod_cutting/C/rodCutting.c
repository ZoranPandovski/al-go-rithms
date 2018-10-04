#include <stdio.h>

const int INF=-500000000;

long long int max(long long int a, long long int b)
{
	return (a<b)? b:a;
}

long long int topDownRodCutting(int p[], int r[], int n)
{
	int i,q;
	//Return memoized value if it exists
	if(r[n]>=0)
		return r[n];

	if(n==0)
		q=0;
	else
		q=INF;

	/* Finds the maximum price by iterating through the array and getting the sum of p[i]
	(which is the price obtained by selling that part of the rod directly) and the optimal
	solution for the rod of length (n-i) */

	for(i=1; i<=n; i++)
		q=max(q,p[i] + topDownRodCutting(p,r,n-i));

	// Memoizing
	r[n]=q;
	return r[n];
}

int main()
{
	int i,n;
	printf("Enter the length of the rod\n");
	scanf("%d",&n);
	int p[n],r[n+1];
	printf("Enter the prices array\n");
	for(i=1; i<n; i++)
		scanf("%d",&p[i]);
	p[n] = INF;

	//Initialising the memoized to INF initially
	for(i=0; i<=n; i++)
		r[i] = INF;

	printf("The maximum price which can be achieved by cutting the rod and selling the pieces is:\n");
	printf("%lld\n", topDownRodCutting(p,r,n));
	return 0;
}