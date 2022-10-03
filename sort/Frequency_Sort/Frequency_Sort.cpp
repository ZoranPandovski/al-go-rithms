// The frequency sort algorithm is used to output elements of an array in descending order of their frequencies. If two elements have the same frequencies, 
// then the element that occurs first in the input is printed first.
// Input: {1, 2, 1, 2, 5, 2, 3, 2, 4}
// Output: Frequency Sort: 2 1 2 5 2
  
// Approach: Here priority queue, (maxHeap) is used to sort.

#include <bits/stdc++.h>
using namespace std;

void frequency_sort(int a[], int n){
    unordered_map<int, int>mp;
    priority_queue< pair<int,int>, vector<pair<int,int>>> maxHeap;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    for( auto i = mp.begin(); i!= mp.end(); i++){
        maxHeap.push({i->second, i->first});
    }
    while (maxHeap.size()>0) {
        int freq = maxHeap.top().first;
        int element = maxHeap.top().second;
        for (int i = 1; i <= freq; i++){
            cout<<a[i]<<" ";
            maxHeap.pop();
        }
    }
}
int main()
{  
    int a[] = {1, 2, 1, 2, 5, 2, 3, 2, 4};
    
    int size = sizeof(a) / sizeof(a[0]);
    
    cout<<"Frequency Sort: ";
    frequency_sort(a, size);

    return 0;
}
