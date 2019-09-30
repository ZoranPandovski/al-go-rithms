//Randomized Quicksort by EUNIX-TRIX

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::srand;
vector<int> rand_quickSort(vector<int>&, int , int);
int partition(vector<int>&, int , int );
int rand_partition(vector<int>&, int, int);
int main()
{
	vector<int> arr, sort_arr;
	int input, p, r;
	cout << "Enter the no. to be sorted" << endl;
	while (cin >> input && input != 9999)
		arr.push_back(input);
	
	p = 0;
	r = arr.size()-1;
	sort_arr = rand_quickSort(arr, p, r);
	typedef vector<int>::iterator iter;
	for (iter i = sort_arr.begin(); i != sort_arr.end(); i++)
	{
		cout << *i << "\t";
	}
	return 0;
}

vector<int> rand_quickSort(vector<int> &arr, int p, int r)
{
	int q;
	if (p < r)
	{
		q = rand_partition(arr, p, r);
		rand_quickSort(arr, p, q - 1);
		rand_quickSort(arr, q + 1, r);
	}
	return arr;
}

int partition(vector<int> &arr, int p, int r)
{
	int x, i, j, tmp;
	x = arr[r];
	i = p - 1;
	for (j = p; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
	    }
	}
	tmp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = tmp;
	
	
	return i + 1;
}

int rand_partition(vector<int> &arr, int p, int r)
{
	int randNo;
	srand(time(NULL));
	randNo = p + rand() % (r - p + 1);
	int tmp = arr[r];
	arr[r] = arr[randNo];
	arr[randNo] = tmp;

	return partition(arr, p, r);
}