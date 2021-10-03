#include<iostream>
using namespace std;
int main()
{
   int n, count = 0;
   cout << "Enter number of elements : ";
   cin >> n;
   int arr[n];
   cout << "Enter " << n << " elements:\n";
   for (int i = 0; i < n; i++)
       cin >> arr[i];
   for (int i = 0; i < n - 1; i++)
       for (int j = i + 1; j < n; j++)
           if (arr[i] > arr[j])
               count++;
   cout <<"Output: "<< count<<". The inversions :";
   for (int i = 0; i < n - 1; i++)
       for (int j = i + 1; j < n; j++)
           if (arr[i] > arr[j])
               cout<<"("<<arr[i]<<","<<arr[j]<<"),";
}
