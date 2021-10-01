/* Program to find all the triplets in an array that add up to a given sum*/
/* Test Case 1
Input: 
array: {1,2,3,4,5,6,7,8,9,15}
sum: 18

Output:
1 2 15 
1 8 9 
2 7 9 
3 6 9 
3 7 8 
4 5 9 
4 6 8 
5 6 7 

*/

/* Test Case 2
Input:   
array: {1,2,3,4,5,6,7,8,9,15}
sum: 15

Output:
1 5 9 
1 6 8 
2 4 9 
2 5 8 
2 6 7 
3 4 8 
3 5 7 
4 5 6
*/


#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<vector<int>> tripletSum(vector<int> arr, int sum){
 
  vector<vector<int>> result;
  sort(arr.begin(),arr.end());
  int n = arr.size();
  
  for(int i=0;i<=n-3;i++){
    vector<int> res;
    int x = sum-arr[i];
    
    int j = i+1;
    int k = n -1;
    while(j<k){
      if(arr[j]+arr[k]==x){
        result.push_back({arr[i],arr[j],arr[k]});
        j++;
        k--;
      }
      else if((arr[j]+arr[k])>x){
        k-=1;
      }
      else if((arr[j]+arr[k])<x){
        j+=1;
      }
    }
  }
  return(result);
}

int main() 
{
    //2 pairs
    vector<int> arr = {1,2,3,4,5,6,7,8,9,15};
    int s =18;

    auto p = tripletSum(arr,s);
    
    if(p.size() == 0){
      cout<<"no pair";
    }
    else{
      for(auto i:p){
        for(int j:i){
          cout<<j<<" ";
        }
        cout<<endl;
      }
    }

   
    return 0;
}
