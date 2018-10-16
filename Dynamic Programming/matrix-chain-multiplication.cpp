#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;
int mcm(int *arr, int n){
    int m[n-1][n-1];   
    for(int k=0; k<n-1; k++){
        m[k][k] = 0;
    } 
    for(int l=2; l<n; l++){
        for(int i=0; i<n-l; i++){
            int j=i+l-1;
            m[i][j] = INT_MAX;
            for(int k=i; k<=j-1; k++){
                int q=m[i][k] + m[k+1][j] + arr[i]*arr[k+1]*arr[j+1];
                if(q<m[i][j]){
                    m[i][j]=q;
                }
            }
        }
    }
    return m[0][n-2];
}
int main(){
    int n;
    cout<<"Enter the no. of elements in array: ";
    cin>>n;
    int *arr = (int*)malloc(n*sizeof(int));
    cout<<"\nEnter array of elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int min_no_of_steps = mcm(arr, n);
    cout<<"\nTotal cost: "<<min_no_of_steps<<"\n";
}
