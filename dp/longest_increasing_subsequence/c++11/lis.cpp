#include <iostream>
#include <set>
#include <vector>

using namespace std;


// this algorithm supports all numeric data types.
template<class T>
multiset<T> LIS(vector<T> const &arr)
{
	multiset<T> lis;

	for(int i = 0; i < arr.size(); i++)
	{
		lis.insert(arr[i]);
		auto it = lis.upper_bound(arr[i]);
		if(it != lis.end())
		{
			lis.erase(it);
		}
	}

	return lis;
}

int main()
{
	vector<int> A{2, 5, 3, 7, 11, 8, 10, 13, 6 };

	multiset<int> L = LIS(A);

	cout << L.size() << endl;

	return 0;

}