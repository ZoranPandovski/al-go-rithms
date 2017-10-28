#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,q;
	cin>>n>>q;
	long long int arr[n],upd[n+1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		upd[i]=0;
	}
	upd[n]=0;
	long long int start,end,val;
	for(int i=0;i<q;i++){
		cin>>start>>end>>val;
		upd[start]+=val;
		upd[end+1]-=val;
	}
	long long int kk=0;
	cout<<"Updated array is : ";
	for(int i=0;i<n;i++){
		kk+=upd[i];
		arr[i]+=kk;
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
