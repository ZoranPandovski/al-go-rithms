/* @author Navneet Jain
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26

 * Given an encoded message containing digits, determine the total number of ways to decode it.

 * Example :
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 * The number of ways decoding "12" is 2.

 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int numDecodings(string A) {
    int sizeA = A.length();
    if(sizeA == 0){
        return 0;
    }
    else if(A[0] - '0' == 0){
        return 0;
    }
    
    std::vector<int> B(sizeA + 1, 1);
    for(int i = 1 ; i < sizeA; i++){
        if(A[i] - '0' == 0 && A[i - 1] - '0' > 2){
            return 0;
        }
        else if(A[i] - '0' == 0 && i != sizeA - 1){
            B[i+1] = 0;
        }
        else if(A[i] - '0' == 0 ){
            B[i+1] = B[i];
        }
        else if(A[i] - '0' <= 6 && A[i-1] - '0' <=2 ){
            B[i + 1] = B[i] + B[i-1];
        }
        else{
            B[i+1] = B[i];
        }
    }

    return B[sizeA];    
}

int main(){
	string A = "123";
	cout << numDecodings(A);
}

