#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[],int n,int i){
    int max=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[max])
        max=l;
    if(r<n && arr[r]>arr[max])
        max=r;
    if(max!=i){
        int t=arr[i];
        arr[i]=arr[max];
        arr[max]=t;
        heapify(arr,n,max);
    }
}

void getMax(int arr[],int k,int i){
    if(arr[i]<arr[0]){
        int t=arr[0];
        arr[0]=arr[i];
        arr[i]=arr[0];
        heapify(arr,k,0);
    }
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>k;
	    for(int i=(k/2)-1;i>=0;i--){
	        heapify(arr,k,i);
	    }
	    for(int i=k;i<n;i++){
	        getMax(arr,k,i);
	    }
	    cout<<arr[0]<<"\n";
	}
	return 0;
}