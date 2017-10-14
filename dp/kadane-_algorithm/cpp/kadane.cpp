#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> v={-2,-1,-5,3,7,-2,5,11,-10,-20,11};
	int n=v.size();
	int mini=*min_element(v.begin(),v.end());
	int maxval=mini,curval=mini;
	for(int i=0;i<n;i++){
		curval=max(curval+v[i],v[i]);
		maxval=max(maxval,curval);
	}
	cout<<"Maximum Subarray Sum = "<<maxval<<endl;
}