/* Kunal Garg
   IIIT Hyderabad  */
#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include <vector>
int arr[1111111];
int temp[1111111];
int n;
using namespace std;

void merge(int l,int m,int r)
{
	int mid = m+1;
	int k=1;
	int safe = l;
	while(l<=m && mid<=r)
	{ 
		if(arr[l] <= arr[mid])
			temp[k++] = arr[l++];
		else 
			temp[k++] = arr[mid++];
	}
	while(l<=m)
		temp[k++] = arr[l++];
	while(mid <=r)
		temp[k++] = arr[mid++];
	for(int i=1;i<k;i++)
		arr[safe+i-1] = temp[i];
	return;
}

void merge_sort(int l,int r)
{
	if(l<r)
	{
		int m = (l+r)>>1;
		merge_sort(l,m);
		merge_sort(m+1,r);
		merge(l,m,r);
		return;
	}
	return;
}

int main()
{

	int pos=1;
	int x;
	int m;
	cin >> m;
	for(int i=1;i<=m;i++)
		cin >> arr[i];
	merge_sort(1,m);
	for(int i=1;i<=m;i++)
		printf("%d ",arr[i]);
	printf("\n");
}





