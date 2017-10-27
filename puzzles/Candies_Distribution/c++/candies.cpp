/*   The problem statement is :
	 We are given n pots of candies and each pot contain some candy in it and we have to distribute candies among k children such that
	 => all the children should get equal number of candies
	 => each child should get maximum possible candies 
	 => one child cannot get candies form more than one pot (use only one pot for one child)
	 
	 Example: 
	 	Let there are 4 pots and candies corresponding to each pot is 3,2,3,9 and the number of children is 2 then we can distribute maximum of 4 candies
		to each child.
		
		Explanation: We distributed 4-4 candoes from the pot containing 9 candies as we can only use one pot for one child, so the maximum possible is 4. 
	
	 Input:  first line n and k (number of pots and candies correspinding to each pot)
	 		 second line n space separated integers representing number of candies in each pot
	 Output: maximum possible candies each child can get.		  	
*/
		
/*   This solution uses binary search approach to solve the problem and solves the problem in O(nlogn) time */
		
#include<iostream>
#include<algorithm>

using namespace std;

bool check(int candies[], int mid, int n, int k){   // this function checks if the mid value can be a answer or not
	int sum = 0;
	for(int i = 0 ; i<n ; i++){
	sum = sum + (candies[i]/mid);
		if(sum >= k)
			return true;	
	}
	return false;
}

int main(){
	
	int n,k;
	cin>>n>>k;
	
	int answer;
	
	int candies[n];
	for(int i=0 ; i<n ; i++){
		cin>>candies[i];
	}	
	
	sort(candies,candies+n);	//sorting candies inside the pot in ascending order
	 
	//we know that minimum and maximum candies to be given to child can be 0 and candies that is present in the last pot after sorting
	int min_candies = 0;
	int max_candies = candies[n-1];
	
	//using binary search technique to solve the problem
	while(min_candies <= max_candies){
		int mid = (min_candies + max_candies)/2;
		
		if(check(candies,mid,n,k)){		// if mid value can be a answer then check for a bigger value than mid for answer
			answer = mid;			
			min_candies = mid+1;
		}
		else{							// if mid value cannot be a answer then check for a smaller value than mid for answer
			max_candies = mid-1;
		}
	}
	
	cout<<answer<<endl;
	
	
	return 0;
}

//@Rahularity21
