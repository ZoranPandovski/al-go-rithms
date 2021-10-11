/*
C++ Program to display all the number pairs in a given array that add up to a given sum 
*/

/* Test Case 1:
Input: 
array: {10,5,0,2,3,-6,9,11}
sum: 5
Output: 
5 0 
2 3 
-6 11 
*/

/* Test Case 2: 
Input: 
array: {10,5,0,2,3,-6,9,11}
sum: 2
Output:
0 2 
*/

#include <iostream>
#include<vector>
#include<unordered_set>

using namespace std;
vector<vector<int>> pairSum(vector<int> arr, int sum){
  unordered_set<int> s;
  vector<vector<int>> result;
  int n = arr.size();
  
  for(int i=0;i<n;i++){
    vector<int> res;
    int x = sum-arr[i];
    if(s.find(x)!=s.end()){
      result.push_back({x,arr[i]});
    }
    s.insert(arr[i]);
  }
  return(result);
}
