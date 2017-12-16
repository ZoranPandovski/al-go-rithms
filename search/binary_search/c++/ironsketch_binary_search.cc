/* AUTH: ironsketch https://github.com/ironsketch
 * I am new to programming. This may be terrible. I am sorry.
 *
 * This is a binary search using c++. A binary search doesn't work if your array/vector is not sorted.
 *
*/ 

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

bool binarySearch(vector<int> &vec, int num){
	if(vec.size() == 0)
		return false;
	else{
		int r = vec.size() - 1;
		int l = 0;
		int mid = vec.size() / 2;
		while(l <= r){
			mid = (l + r) / 2;
			if(num > vec[mid])
				l = mid + 1;
			else if(num < vec[mid])
				r = mid - 1;
			else
				return true;
				
		}
	}
	return false;
}

int main(){
	vector<int> v;
	int size;
	cout << "How big do you want the vector(array) to be? " << endl;
	cin >> size;
	
	for(int i = 0; i < size; i++){
		v.push_back(i);
	}

	int find;
	bool found;
	clock_t t;
	cout << "Now let's search for a numbers and time it!" << endl;
	cout << "type in one of those numbers: " << endl;
	cin >> find;
	t = clock();
	found = binarySearch(v,find);
	t = clock() - t;
	if(found){
		cout << "We did find " << find << " and it took " << (float)t / CLOCKS_PER_SEC << " sec" << endl;
	} else{
		cout << "We did not find " << find << " and it took " << (float)t / CLOCKS_PER_SEC << " sec" << endl;
	}
	return 0;
}
