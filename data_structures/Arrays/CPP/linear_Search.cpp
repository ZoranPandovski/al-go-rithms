/*
Linear search key

A simple approach is to do a linear search, i.e  

Start from the leftmost element of arr[] and one by one compare x with each element of arr[]
If x matches with an element, then element present in array  
other wise it is not present in array .

Example :  enter size of array
4
Enter array element
1 3 4  5
enter key to be search
4
present
position3
 
*/


#include<bits/stdc++.h>
using namespace std;
int main(){
 int n; // size of array
 cout<<"enter size of array"<<endl;
 cin>>n;
 int arr[n]; // array to store all the elements
 cout<<"Enter array element\n";
 for(int i=0 ;i<n;i++){
     cin>>arr[i]; // loop for entering array
 }
 int key; // key variable to be search
 cout<<"enter key to be search"<<endl;
 cin>>key;
 int i =0 ,flag =0 ,count =0,lastpos;
 for(i =0 ; i<n ;i++) {
        if(key == arr[i]){
           // cout<<"present"<<" "<<i+1<<endl;
           lastpos=i+1;
            flag =1;
            break;
           // break; using this break statment present will run only 1 time if same element array then it will stop at first time
           // using break time compx O(1)
           // without break we can print both 1 or all position of key present in array
        }
        count++;
 }
 if(flag == 0){
    cout<<"Not present"<<endl;
 } else {

   cout<<"present \nposition "<<lastpos<<endl; // time compx O(n)

 }

return 0;
}

