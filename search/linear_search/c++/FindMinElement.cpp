//FindMinElement

/*
The linear search algorithm is the most simple algorithm you can think of.
In this example (written in C++) we see an example of use to find the minimum element in a vector.

The vector class is part of the Standard Template Library a.k.a. STL (http://www.cplusplus.com/reference/stl/ ).
Using the link's definition for this container: "Vectors are sequence containers representing arrays that can change in size."

Our function receives a parameter, a vector object. Our vector contains integer elements. To know how many elements are inside it,
we use the size method that returns an integer with the total number of 
elements on the vector.

If the current value evaluated is lower than the value of the min variable, min will be update with the current value of the vector's element.

Once our loop is finished, our function returns the minimum value via the min variable
*/

#include <iostream>
#include <vector>

using namespace std; 

int findSmallest(vector <int> list){
	int min=65536;
	for(int i=0;i<list.size();i++){
		if(min>list[i]) min=list[i];
	}
  return min;
}

int main(){
  int num=0;
  cout << "Please insert the number of elements:\n";
  cin >> num;
  int v=0;
  vector<int> list; //create an empty vector
  for(int i=0;i<num-1;i++){
    cout << "Insert a number:\n";
    cin >> v;
    list.push_back(v); //insert the number on the vector
  }

  cout << findSmallest(list) << "\n";
  return 0;
}
