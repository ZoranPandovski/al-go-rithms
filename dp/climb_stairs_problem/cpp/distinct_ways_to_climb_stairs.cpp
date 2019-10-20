/*@author Navneet Jain
 * You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include<iostream>
using namespace std;

long countSteps(int A){
    if(A <= 0){
        return 0;
    }
    else if(A ==1){
        return 1;
    }
    else if(A == 2){
        return 2;
    }
	//Since only way to reach nth stair is via n-1 stair and n-2 stair. Hence adding those two to get the result recursively
    return countSteps(A - 1) + countSteps(A -2);


}

int climbStairs(int A) {
    return countSteps(A);
    
}

int main(){
	int stair_to_reach;
	cin >> stair_to_reach;
	cout << climbStairs(stair_to_reach);
}
