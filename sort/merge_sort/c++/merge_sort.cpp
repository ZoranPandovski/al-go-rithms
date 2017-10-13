#include <bits/stdc++.h>
using namespace std;
int arr[1000000],a[1000000],b[1000000];
void merge(int l,int m,int h)
{
	int len1=(m-l+1),len2=(h-m);
	int i=0,j=0,k=l;
	for(i=0;i<len1;i++)
		a[i]=arr[l+i];
	for(i=0;i<len2;i++)
		b[i]=arr[m+1+i];
	i=0;
	while(i<len1 && j<len2)
	{
		if(a[i]<=b[j])
			arr[k]=a[i++];
		else if(a[i]>b[j])
			arr[k]=b[j++];
		k++;
	}
	while(i<len1)
	{
		arr[k]=a[i++];
		k++;
	}
	while(j<len2)
	{
		arr[k]=b[j++];
		k++;
	}
}
void msort(int l,int h)
{
	if(l<h)
	{
		int mid=(l+h)>>1;
		msort(l,mid);
		msort(mid+1,h);
		merge(l,mid,h);
	}
}
int main()
{
	int n,i,j;
	i=0;
	n=0;
	cout<<"Enter how many numbers you want to sort : ";
	cin>>n;
	cout<<"Enter numbers"<<endl;
	for(i=0;i<n;i++)
		cin>>arr[i];
	msort(0,n-1);
	cout<<"Sorted numbers are : ";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl; 
	return 0;
}