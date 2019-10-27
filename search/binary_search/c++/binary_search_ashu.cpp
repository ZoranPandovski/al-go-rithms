#include<iostream>
#include<vector>

using namespace std;

int binary_search(vector<int>& a, int val){
	int start = 0, end = a.size() - 1;
	int mid;
	while(start<=end){
		mid = (start + end)/2;

		if(a[mid] == val) return mid;

		else if(a[mid] < val) start = mid + 1;
		else end = mid - 1; 
	}

	return -1;
}

int main(void)
{
	/* code */
	int n;
	cout << "Enter size of array : \n";
	cin >> n;

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	int x;
	cin >> x;

	cout << "Index of searched element : " << binary_search(v, x) << endl;
	return 0;
} 