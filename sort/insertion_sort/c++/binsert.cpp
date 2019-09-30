#include <bits/stdc++.h>
using namespace std;

int binarysearch(int *a,int k,int *ans)
{
	int l=0;
	int h=k-1;
	int m=l+(h-l)/2;
	int index;
	int p=k;
	while(l<h)
	{
		(*ans)++;
		m=l+(h-l)/2;
		if(a[m]>a[p])
		{
			h=m-1;
		}
		else
		{
			l=m+1;
		}

	}
	if(a[l]>a[p])
	{index=l; (*ans)++;}
	else
	{
		index=l+1; (*ans)++;
	}
	return index;
}

int insert(int *a,int n)
{
	int ans=0;
	for(int i=1;i<n;i++)
	{
		int p=i;
		int x=a[p];
		int j=i-1;
		int index=binarysearch(a,p,&ans);
		//cout<<index<<endl;
		while(j>=index)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;

	}
	return ans;
}

int main()
{
	int n;
	cin>>n;
	int *a=new int[n+1];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<insert(a,n)<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}