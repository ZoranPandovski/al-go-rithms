#include <bits/stdc++.h>
using namespace std;

int partition (vector<int> &v, int low, int high){
	int pivot = v[high];
	int i = (low - 1);

	for (int j = low; j <= high- 1; j++){
		if (v[j] <= pivot){
            i++;    // increment index of smaller element
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}

void quickSort(vector<int> &v, int low, int high){
	if (low < high){
		int pi = partition(v, low, high);
		quickSort(v, low, pi - 1);
		quickSort(v, pi + 1, high);
		//pi => partition index
	}
}


int main(){
	int n;
	cout<<"Enter the number of elements you want to enter: "<<endl;
	cin>>n;tim
	vector<int> v(n);
	cout<<"Enter the elements: "<<endl;
	for(int i=0; i<n; i++){
		cin>>v[i];
	}
	
	quickSort(v,0,n-1);
	cout<<"Sorted Elements: "<<endl;
	for(int i=0; i<n; i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}