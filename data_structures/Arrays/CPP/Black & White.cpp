#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	//code here
	string str;
	cin>>str;
	int n=str.length();
	int a[n];
	int count=0;
	for(int i=0;i<n;i++){
		a[i]=str[i]-48;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(a[0]==a[1]){
			cout<<1;
			return 0;
		}
		if(a[0]!=a[1]){
			cout<<0;
			return 0;
		}
	}
	if(n>2 && a[0]==a[1]){
		if(a[1]!=a[2]){
			a[0]=1-a[0];
			count++;
		}
		else{
			a[1]=1-a[1];
			count++;
		}
	}
	for(int i=1;i<n-1;i++){
		if(a[i]==a[i+1]){
			a[i+1]=1-a[i+1];
			count++;
		}
	}
	cout<<count;
	return 0;
}
