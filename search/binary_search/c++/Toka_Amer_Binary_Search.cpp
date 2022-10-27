/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


int BinarySearch(int arr[],int start,int end,int number) {
    int mid = (start + end)/2;
    if(start > end) {
        return -1;
    }
    if(arr[mid] == number) {
        return mid;
    }
    else if(arr[mid] < number) {
        return BinarySearch(arr,mid+1,end,number);
    }
    else if(arr[mid] > number) {
        return BinarySearch(arr,start,mid-1,number);
    }
    
    return 0;
}

//test the algorithm

int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    //trying to find number that exsist in the array
    int result1 = BinarySearch(arr,0,9,8);
    if( result1 == -1) {
        cout << "number 8 doesn't in the array" << endl;
    }
    else {
        cout << "number 8 found at index: " << result1 << endl;
    }
    //trying to find number that  doesn't exsist in the array
    int result2 = BinarySearch(arr,0,9,20);
    if( result2 == -1) {
        cout << "number 20 doesn't in the array" << endl;
    }
    else {
        cout << "number 20 found at index: " << result2 << endl;
    }
    return 0;
}
