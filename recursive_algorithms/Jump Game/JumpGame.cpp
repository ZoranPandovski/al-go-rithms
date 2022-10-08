#include<bits/stdc++.h>
using namespace std;

int CanReach(vector<int> &arr, int ind)
{
    if(ind == arr.size()-1)
        return 1;

    for(int i=ind+1; i<arr.size() && i<=ind+arr[ind]; i+=1)
    {
        if(CanReach(arr,i))
            return 1;
    }
    return 0;
}

int main()
{
    int num;
    cout<<"How many numbers do you want to enter?\n";
    cin>>num;
    vector <int> arr(num);
    cout<<"Enter the no.s\n";
    for(int i=0;i<num; i++)
        cin>>arr[i];

    cout<<((CanReach(arr,0)==1)?"CAN reach!":"CAN'T Reach");
}
