#include<iostream>
using namespace std;


int main(){
    int n1,n2;
    cin>>n1;     //taking first input and creating array to store first array
    int arr1[n1];
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }

    cin>>n2;    //taking second input and creating array to store second array
    int arr2[n2];
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }

    int temp1=0,temp2=0,temp=0;   //declaring temperory variables for furher process
    int arr[n1+n2];               //declaring array to store full sorted array

    while(temp1!= n1 && temp2!=n2){    //checking conditions whether all elements in any one of the array compare or not
        if(arr1[temp1]>arr2[temp2]){   //comparing elements in two arrays
            arr[temp++]=arr2[temp2++];  // assinging snaller one to array and going for next element in array which contain small element 

        }
        else if(arr2[temp2]>arr1[temp1]){// assinging snaller one to array and going for next element in array which contain small element 
            arr[temp++]=arr1[temp1++];
        }
        else{                           //if both elements are same then assigning both the arrray and going for next elements in arrays
            arr[temp++]=arr1[temp1++];
            arr[temp++]=arr2[temp2++];
        }
    }

    for(int i=temp1;i<n1;i++){    //after checking complete elements in any on of the array adding remaining elements of other array to full sorted array
        arr[temp++]=arr1[i];
    }
    for(int i=temp2;i<n2;i++){    //after checking complete elements in any on of the array adding remaining elements of other array to full sorted array
        arr[temp++]=arr2[i];
    }


    for(int i=0;i<temp;i++){
        cout<<arr[i]<<" ";    //printing sorted array
    }

    return 0;
}