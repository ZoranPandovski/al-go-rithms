#include<bits/stdc++.h>
using namespace std;

int bin_search(int value,int ar[100001],int m)
{
	int l,r,mid;
	l=0;r=m-1;
	while(l<=r)
	{
		mid = (l+r)/2;
		if(ar[mid]==value)
			return mid;
		else if(ar[mid]>value)
			r = mid-1;
		else
			l = mid+1;
	}
	return -1;
}

int main()
{
	int a[100001],b[100001],arr[100001],val,n,m,temp;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<m;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	sort(a,a+m);
	sort(b,b+m);
	val = 0;
	for(int i=0;i<n;i++)
	{
		temp = bin_search(arr[i],a,m);
		if(temp==-1)
		{
			temp = bin_search(arr[i],b,m);
			if(temp==-1)
				val=val;
			else
				val = val-1;
		}
		else
			val = val +1;
	}
	cout<<val<<endl;
	return 0;
}
