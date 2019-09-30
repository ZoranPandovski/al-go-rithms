#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int start,int end,int val)
{
	int mid = (start+end)/2;
	if(start>=end)
		return start;

	if(arr[mid]>val)
		return binary_search(arr,start,mid,val);
	else
		return binary_search(arr,mid+1,end,val);

	return -1;
}

void insertion_sort(int arr[],int start,int end){

	//cout<<"Insertion Sort is called\n";
	for(int i=start+1;i<end;i++)
	{
		int pos = binary_search(arr,start,i,arr[i]);
		int x = arr[i];
		for(int j=i-1;j>=pos;j--)
			arr[j+1]=arr[j];
		arr[pos]=x;
	}
	return;
}

void merge(int arr[],int start,int mid,int end){

	int s1 = mid-start+1;
	int s2 = end-mid;
	int *l_array = new int[s1+1];
	int *r_array = new int[s2+1];

	for(int i=0;i<s1;i++)
		l_array[i]=arr[start+i];

	for(int i=0;i<s2;i++)
		r_array[i]=arr[mid+1+i];

	l_array[s1] = INT_MAX;
	r_array[s2] = INT_MAX;
	int k=0;
	int l=0;
	for(int i=start;i<=end;i++){

		if(l_array[k]<=r_array[l])
			{arr[i]=l_array[k++];}
		else
			{arr[i]=r_array[l++];}
	}

	delete [] l_array;
	delete [] r_array;
	return  ;

}

void merge_sort(int arr[],int start,int end)
{	
	//cout<<"Merge sort is called\n";
	if(start<end){

		int mid = (start+end)/2;
		if(mid-start<55)
			insertion_sort(arr,start,mid+1);
		else
			merge_sort(arr,start,mid);
		
		if(end-mid<55)
			insertion_sort(arr,mid+1,end+1);
		else
			merge_sort(arr,mid+1,end);
		
		merge(arr,start,mid,end);


	}
	return ;
}

int* create_random_array(int n){

	int *arr = new int[n];
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{		
		arr[i]=rand()%100;
	}
	return arr;
}

int main(){

	int n;
	cout<<"Enter the size of the array\n";
	cin>>n;
	int count = 0 ;
	int *arr = create_random_array(n);
	
	merge_sort(arr,0,n-1);
	
	for (int i = 0; i < n; ++i)	
	{
		cout<<arr[i]<<" ";
	}
	
	delete [] arr;
	return 0;

}