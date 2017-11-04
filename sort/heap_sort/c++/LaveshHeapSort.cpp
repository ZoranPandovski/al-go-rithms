#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
void maxheap(int *a,int n,int i)
{
	//if(n==1)
	//	return;
	int max=i;
	if(i*2+1<n && a[i*2+1]>a[max])
	{	max=i*2+1;
	}
	else if(i*2+2<n && a[i*2+2]>a[max])
	{	
		max=i*2+2;
	}
	if(max!=i)
	{
		swap(a[i],a[max]);
		maxheap(a,n,max);
	}
}
void heapsort(int *a,int n)
{	int k=n;
	for(int i=n/2-1;i>=0;i--)
	maxheap(a,n,i);
	for(int i=0;i<n-1;i++)
	{
		swap(a[0],a[k-1]);
		k--;
		maxheap(a,k,0);
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	heapsort(a,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
