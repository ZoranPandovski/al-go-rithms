#include <bits/stdc++.h>
using namespace std;

//this programs check in 0(n) complexity that the array inputed is sorted or not
//if the input array is sorted it return 1 otherwise return 0

//working:
/*
In each iteration it checks that the next elemnt of array must be equal to or greter than the current elemnt

If the next element is smaller than current element than the if condition satisifes and function returns 0

if whole loop ends and the compiler doesnt find any such case then it returns 1 which means array is sorted

*/

bool isSorted(int arr[], int n)
{
    if (n == 1 || n == 0)
        return true;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
            return false;
    }
    return true;
} //0(n) --> tc


int main()
{
    int arr[] = {7, 20, 30, 10};
    cout << isSorted(arr, 4);
    return 0;
}
