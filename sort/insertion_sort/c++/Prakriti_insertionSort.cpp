#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"Enter the number of items: ";
	int n,item;
	cin>>n;
	int a[n];
	//input for array items
	for(int i=0;i<n;i++)
		cin>>a[i];
	//sorting
	for(int i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{	item=a[i];
			int j=i-1;
			while(a[j]>item && j>=0)
			{	a[j+1]=a[j];
				j--;
			}
			a[j+1]=item;
		}
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
