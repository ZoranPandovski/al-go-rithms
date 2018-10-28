#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
  
#define all(c) c.begin(), c.end() 
  
// Each job is represented as a pair of int and pair. 
// This is done to provide implementation simplicity 
// so that we can use functions provided by algorithm 
// header 
typedef pair<int, pair<int, int> > job; 
  
// compare function is given so that we can specify 
// how to compare a pair of jobs 
bool cmp_pair(job a, job b) 
{ 
    int a_Li, a_Ti, b_Li, b_Ti; 
    a_Li = a.second.first; 
    a_Ti = a.second.second; 
    b_Li = b.second.first; 
    b_Ti = b.second.second; 
  
    // To compare a/b and c/d, compare ad and bc 
    return (a_Li * b_Ti) > (b_Li * a_Ti); 
} 
  
void printOptimal(int L[], int T[], int N) 
{ 
    vector<job> list; // (Job Index, Si, Ti) 
  
    for (int i = 0; i < N; i++) { 
        int t = T[i]; 
        int l = L[i]; 
  
        // Each element is: (Job Index, (Li, Ti) ) 
        list.push_back(make_pair(i + 1, make_pair(l, t))); 
    } 
  
    stable_sort(all(list), cmp_pair); 
  
    // traverse the list and print job numbers 
    cout << "Job numbers in optimal sequence are\n"; 
    for (int i = 0; i < N; i++)  
        cout << list[i].first << " ";    
  
} 
  
// Driver code 
int main() 
{ 
    int L[] = { 1, 2, 3, 5, 6 }; 
    int T[] = { 2, 4, 1, 3, 2 }; 
    int N = sizeof(L) / sizeof(L[0]); 
    printOptimal(L, T, N); 
    return 0; 
} 
