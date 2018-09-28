//this is optimized . here number of swaps will be less;
//time complexity:
//best case: O(n)
//Average and worst case: O(n²)
//space complexity O(1);

#include<iostream>
using namespace std;

void bubbleSort(int a[],int n){
    int count=0;
    for(int i=0;i<n-1;i++){
        bool isSorted=true;
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                isSorted=false;

            }
            count++;
            if(isSorted){
                break;
            }
        }

    }
    cout<<"Number of swaps in optimised: "<<count<<endl;

}
int main(){
    int a[]={6,1,3,4,5};
    int n=sizeof(a)/sizeof(int);
    cout<<"Array before sorting :"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";

    }
    cout<<endl;
    bubbleSort(a,n);
    cout<<"Array after sorting :"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";

    }
    return 0;

}


