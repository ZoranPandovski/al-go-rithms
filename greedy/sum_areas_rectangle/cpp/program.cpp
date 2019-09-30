
// CPP code to find sum of all 
// area rectangle possible 
#include <bits/stdc++.h> 
using namespace std; 
  
int MaxTotalRectangleArea(int a[],  
                          int n) 
{ 
    sort(a, a + n, greater<int>()); 
  
    int sum = 0; 
    bool flag = false; 
  
    int len; 
      
    for (int i = 0; i < n; i++)  
    { 
        if ((a[i] == a[i + 1] || a[i] -  
            a[i + 1] == 1) && (!flag))  
        { 
            flag = true; 
  
            len = a[i + 1]; 
  
            i++; 
        } 
  
        else if ((a[i] == a[i + 1] ||  
                a[i] - a[i + 1] == 1) && (flag))  
            { 
                sum = sum + a[i + 1] * len; 
  
                flag = false; 
  

                i++; 
            } 
    } 
  
    return sum; 
} 
  
// Driver code 
int main() 
{ 
    int a[] = { 10, 10, 10, 10, 
                11, 10, 11, 10, 
                9, 9, 8, 8 }; 
    int n = sizeof(a) / sizeof(a[0]); 
      
    cout << MaxTotalRectangleArea(a, n); 
      
    return 0; 
} 