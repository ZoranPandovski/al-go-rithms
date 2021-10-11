#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
	int a[10], i, j, temp, n;
	cout<<"Enter the Size :: ";
	cin>>n;
	cout<<"Enter the Array Elements :: "<<endl;
	for(i=0; i<n; i++)
	{
		cout<<"The "<<i<<" element is :: ";
		cin>>a[i];
	}
	cout<<"Unsorted Array is :: ";
	for(i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	for(i=0; i<n-1; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	cout<<endl<<"Sorted Array is :: ";
	for(i=0; i<n; i++)
		cout<<a[i]<<" ";
}
