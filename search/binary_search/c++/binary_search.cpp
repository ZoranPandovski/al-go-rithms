#include<bits/stdc++.h>
using namespace std;
bool binarySearchIterative(int list[], int first, int end, int item)
{

	int middle;

	while(first <= end)
	{
	     middle =first + (end- first)/2;
	     if(list[middle] == item)
	        {
			return true;
		}
		if(list[middle] < item)
		{
			first = middle + 1;
		} else
		{
			end = middle - 1;
		}
	}
	return false;
}

bool binarySearchRecursive(int list[], int first, int end, int item)
{

	int middle = (first + end)/2;

	if(list[middle] == item)
	{
		return true;
	}
	if(first >= end)
	{
		return false;
	}
	if(list[middle] < item)
	{
		return binarySearchRecursive(list, middle+1, end, item);
	} else
	{
		return binarySearchRecursive(list, first, middle-1, item);
	}

}

int main(int argc, char const *argv[])
{
 cout << "Please, enter the size of the list." << endl;
  int size, value, option;
  bool find;
 cin >> size;
  int *list = new int[size];
  for(int i = 0; i < size; i++)
  {
   cout << "Enter the element " << i << " of the list." << endl;
   cin >> list[i];
  }
 cout << "Now, enter a value to be searched in the list." << endl;
 cin >> value;
  cout << "Now, would you like to use a binary search iterative (0) or a binary search recursive(1)." <<endl;
 cin >> option;
  switch (option) {
    case 0:
      {
        auto start =chrono::steady_clock::now();
        find = binarySearchIterative(list, 0, size-1, value);
        auto end =chrono::steady_clock::now();
        auto diff = end - start;
        if(find)
        {
         cout << "You find the element using the binary search iterative." << endl;
        }
        else{
          cout << "You not find the element using the binary search iterative." <<endl;
        }
       cout << "And the time of search was " <<chrono::duration <double,milli> (diff).count() << " ms." << endl;
      }
      break;
    case 1:
      {
        auto start =chrono::steady_clock::now();
        find = binarySearchRecursive(list, 0, size-1, value);
        auto end =chrono::steady_clock::now();
        auto diff = end - start;
        if(find)
        {
          cout << "You find the element using the binary search recursive." <<endl;
        }
        else
	{
         cout << "You not find the element using the binary search recursive." << endl;
        }
       cout << "And the time of search was " << chrono::duration <double, milli> (diff).count() << " ms." << endl;
      }
      break;
    default:
      cout << "This isn't a valid option, please restart the program." << endl;
      break;
  }
  delete[] list;
	return 0;
}
