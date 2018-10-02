#include <iostream>
#include <bitset>
#define fr(a,b,c) for(int a = b, _ = c; a < _; a++)
using namespace std;
const int mx = 50100;
bool solve(int set[], int n, int s){
  bitset<mx> sums;
	sums[0] = 1;
  fr(i,0,n){
    sums |= sums << set[i];
  }
  return sums[s];
}
int main(){
	int set[] = {3,2,7,1};
  int s = 6;
  int n = sizeof(set)/sizeof(set[0]);
  if(solve(set, n, s)){
    cout << "Found a subset with given sum!" << endl;
  }else{
    cout << "No subset with given sum!" << endl;
  }
}
