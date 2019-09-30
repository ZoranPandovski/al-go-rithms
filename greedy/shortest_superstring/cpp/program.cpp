// C++ program to find shortest superstring using Greedy 
// Approximate Algorithm 
#include <bits/stdc++.h> 
using namespace std; 
  
// Utility function to calculate minimum of two numbers 
int min(int a, int b) 
{ 
    return (a < b) ? a : b; 
} 
  
// Function to calculate maximum overlap in two given strings 
int findOverlappingPair(string str1, string str2, string &str) 
{ 
    // max will store maximum overlap i.e maximum 
    // length of the matching prefix and suffix 
    int max = INT_MIN; 
    int len1 = str1.length(); 
    int len2 = str2.length(); 
  
    // check suffix of str1 matches with prefix of str2 
    for (int i = 1; i <= min(len1, len2); i++) 
    { 
        // compare last i characters in str1 with first i 
        // characters in str2 
        if (str1.compare(len1-i, i, str2, 0, i) == 0) 
        { 
            if (max < i) 
            { 
                //update max and str 
                max = i; 
                str = str1 + str2.substr(i); 
            } 
        } 
    } 
  
    // check prefix of str1 matches with suffix of str2 
    for (int i = 1; i <= min(len1, len2); i++) 
    { 
        // compare first i characters in str1 with last i 
        // characters in str2 
        if (str1.compare(0, i, str2, len2-i, i) == 0) 
        { 
            if (max < i) 
            { 
                //update max and str 
                max = i; 
                str = str2 + str1.substr(i); 
            } 
        } 
    } 
  
    return max; 
} 
  
// Function to calculate smallest string that contains 
// each string in the given set as substring. 
string findShortestSuperstring(string arr[], int len) 
{ 
    // run len-1 times to consider every pair 
    while(len != 1) 
    { 
        int max = INT_MIN;  // to store  maximum overlap 
        int l, r;   // to store array index of strings 
        // involved in maximum overlap 
        string resStr;  // to store resultant string after 
        // maximum overlap 
  
        for (int i = 0; i < len; i++) 
        { 
            for (int j = i + 1; j < len; j++) 
            { 
                string str; 
  
                // res will store maximum length of the matching 
                // prefix and suffix str is passed by reference and 
                // will store the resultant string after maximum 
                // overlap of arr[i] and arr[j], if any. 
                int res = findOverlappingPair(arr[i], arr[j], str); 
  
                // check for maximum overlap 
                if (max < res) 
                { 
                    max = res; 
                    resStr.assign(str); 
                    l = i, r = j; 
                } 
            } 
        } 
  
        len--;  //ignore last element in next cycle 
  
        // if no overlap, append arr[len] to arr[0] 
        if (max == INT_MIN) 
            arr[0] += arr[len]; 
        else
        { 
            arr[l] = resStr;   // copy resultant string to index l 
            arr[r] = arr[len];  // copy string at last index to index r 
        } 
    } 
    return arr[0]; 
} 
  
// Driver program 
int main() 
{ 
    string arr[] = {"catgc", "ctaagt", "gcta", "ttca", "atgcatc"}; 
    int len = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "The Shortest Superstring is "
         << findShortestSuperstring(arr, len); 
  
    return 0; 
} 