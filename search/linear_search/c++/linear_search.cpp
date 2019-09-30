#include <bits/stdc++.h>
using namespace std;
int search(int arr[],int n,int x);
int main()
{
	int n,ans=0,key;
	cout<<"enter size of array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter "<<n<<" numbers: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter number you want to search: ";
	cin>>key;
	ans = search(arr,n,key);
	if(ans!=-1)
	{	
		cout<<"Number found at "<<ans+1<<"\n";
	}
	else
	{
		cout<<"Number not found\n";
	}
	return 0;
}
int search(int arr[], int n, int x)
{
    int i;
    for (i=0; i<n; i++)
        if (arr[i] == x)
         return i;
    return -1;
}