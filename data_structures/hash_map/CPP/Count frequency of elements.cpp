#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[6] = {1,2,2,1,3,4}; // Here 1 is 2 times, 2 is 2 times and 3 and 4 is 1 time
    map<int,int> m;
    for(int i=0;i<6;i++){
        m[arr[i]]++; // Stores the frequency for each element
    }
    for(auto [x,y]:m){
        cout<<"Element: "<<x<<" "<< "Frequency: "<<y<<endl;
    }

    return 0;
}
