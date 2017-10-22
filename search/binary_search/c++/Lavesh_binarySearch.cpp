#include<iostream>
#include<stdio.h>
using namespace std;
int bin_search(int *a,int item,int len,int low,int high)
{
	int mid=(high+low)/2;
	if(item==a[mid])
		return mid;
	if(item<mid)
	{	high=mid-1;
		bin_search(a,item,len,low,high);	
	}
	else if(item>mid)
	{	low=mid+1;
		bin_search(a,item,len,low,high);	
	}
}
int main()
{
	int n;
	cout<<"Enter no. in array: ";
	cin>>n;
	int a[n];
	cout<<"Array elements: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	int item;
	cout<<"Enter item: ";
	cin>>item;
	int index=bin_search(a,item,n,0,n-1);
	cout<<index+1;
	return 0;
}
