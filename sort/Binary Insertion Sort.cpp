#include <bits/stdc++.h>
#include <iostream>



using namespace std ;

//Variable indicating no of comparisons in BS
int binarysearch;
//Binary Search by dividing into 2 subparts findind data and return  its location
int BS(int arr[],int data,int low,int high){
	int mid =(low +high)/2 ;

	if (low == high) {
		
		return high ;
}
	if (data > arr[mid]){
		binarysearch++;
		return BS(arr,data,mid+1,high);
		
	}
	if (data <arr[mid]) {
		binarysearch++;
		return BS(arr,data,low,mid);
		
	}
	if(data == arr[mid]){
	binarysearch++;
	return mid ;
}
}

void BIS(int arr[],int n){
	int location; //where select should be inserted
	for(int i =1;i<n;i++){
		location = BS(arr,arr[i],0,i);
		int temp =arr[i];
		//Move all elements after location
		for (int j = i - 1; j >= location ; j--)
            arr[j + 1] = arr[j];
		arr[location]= temp ;	
	}
}


int main(){
	int n;
	cin>>n;

	binarysearch =0 ;

	int *arr =new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	BIS(arr,n);
	cout<<binarysearch<<endl;
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}