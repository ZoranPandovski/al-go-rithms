#include<iostream>
#include<vector>
using namespace std;

int hammingDistance(const vector<int> &A) {
    long long int sol = 0;
    int n = A.size();
    int M = 1000000007;
    int b = 1;
    for(int i = 0; i < 32; i++) {
        int setBits = 0;
        for(int j = 0; j < A.size(); j++) {
            int t = A[j] & b;
            if(t > 0){
                setBits++;
            }
        }
        b *= 2;
        sol = (sol + (setBits * ((n - setBits) * 2)%M))%M ;
    }
    sol = sol%M;
    return (int)sol;
}

int main() {
    vector<int> A = {4,5,63,2,5,3,6,8,5,4,9};
    int distance = hammingDistance(A);
    cout << "Sum of pairwise hamming distance : " << distance << endl;
}

