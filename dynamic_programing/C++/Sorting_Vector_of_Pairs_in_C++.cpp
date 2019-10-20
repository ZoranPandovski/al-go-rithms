/*
Sorting Vector of Pairs in C++ | Set 1 (Sort by first and second)
What is Vector of Pairs?
A pair is a container which stores two values mapped to each other, and a vector containing multiple number of such pairs is called a vector of pairs

Sorting the vector elements on the basis of second element of pairs in ascending order.
There are instances when we require to sort the elements of vector on the basis of second elements of pair. For that, we modify the sort() function and we pass a third argument, a call to an user defined explicit function in the sort() function.

*/

// C++ program to demonstrate sorting in vector 
// of pair according to 2nd element of pair 
#include<bits/stdc++.h> 
using namespace std; 
  
// Driver function to sort the vector elements 
// by second element of pairs 
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 
  
int main() 
{ 
    // declaring vector of pairs 
    vector< pair <int, int> > vect; 
  
    // Initialising 1st and 2nd element of pairs 
    // with array values 
    int arr[] = {10, 20, 5, 40 }; 
    int arr1[] = {30, 60, 20, 50}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    // Entering values in vector of pairs 
    for (int i=0; i<n; i++) 
        vect.push_back( make_pair(arr[i],arr1[i]) ); 
  
    // Printing the original vector(before sort()) 
    cout << "The vector before sort operation is:\n" ; 
    for (int i=0; i<n; i++) 
    { 
        // "first" and "second" are used to access 
        // 1st and 2nd element of pair respectively 
        cout << vect[i].first << " "
             << vect[i].second << endl; 
  
    } 
  
    // Using sort() function to sort by 2nd element 
    // of pair 
    sort(vect.begin(), vect.end(), sortbysec); 
  
    // Printing the sorted vector(after using sort()) 
    cout << "The vector after sort operation is:\n" ; 
    for (int i=0; i<n; i++) 
    { 
        // "first" and "second" are used to access 
        // 1st and 2nd element of pair respectively 
        cout << vect[i].first << " "
             << vect[i].second << endl; 
    } 
    return 0; 
} 

/*
Output:

 
The vector before applying sort operation is:
10 30
20 60
5 20
40 50
The vector after applying sort operation is:
5 20
10 30
40 50
20 60
*/