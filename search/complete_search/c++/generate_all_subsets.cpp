// author: Youssef Ali (https://github.com/youssefAli11997)

/*
  - Applying the complete search technique to generate all subsets(sub arrays) of an array.
  - Example problem to find all subsets that their elements add up to 100
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> a = {0, 72, 21, 15, 36, 55, 81, 9, 27, 42, 63, 12, 18, 100};
vector<int> subset; // current subset to test
bool solution = false; // tells whether at least one solution was found or no solution was found

void complete_search(int idx, int sum){
	if(idx > a.size() || sum > 100) // can't step further or it won't help, go back
		return;
	if(sum == 100){ // a valid subset was found
		if(!solution) // set it to true at the first time we found a valid subset
      solution = true;
		cout<<"100 = ";
		for(int i=0; i<subset.size(); i++){ // print that valid subset
			cout<<subset[i];
			if(i<subset.size()-1)
				cout<<" + ";
		}
		cout<<endl;
		return;
	}
  // take it
	subset.push_back(a[idx]);
	complete_search(idx+1, sum+a[idx]);
  // leave it
	subset.pop_back();
	complete_search(idx+1, sum);
}

int main(){
	complete_search(0,0); // let the search begin, we begin at index 0 and no summation yet(sum = 0)
	if(!solution) // no solution was found
		cout<<"Can't reach 100\n";
	return 0;
}
