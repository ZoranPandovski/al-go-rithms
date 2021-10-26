#include <iostream>
#include <stdlib.h>
using namespace std;

//dnf sort problem
//sort 0s 1s and 2s in an efficient way


/*Steps to do
1) take 3 variables to denote 3 postions and initialize:a)left(as -1),right(as size-1) and middle(as 0)
2)make a while loop to run until middle conflicts with right
3)now check-->
for 0's increase left by 1 then swap between left and middle then increase mid by 1
for 1's just increase middle by 1
for 2's swap right and middle and reduce right by 1(here we donot move middle, as after swap 
the element on middle positon will otherwise remain unchecked)
4)thats it ;)
*/


//function to swap
void swap(int *a, int *b){
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

int main(){
    int *arr;
    int size;

    //input of data
    cout<<"enter the size of the array: ";
    cin>>size;
    arr = (int *)malloc(size * sizeof(int));
    cout << "enter the elements: " << endl;

    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }
    int mid = 0;
    int prev = -1;
    int last = size - 1;



    //actual algo implementation here
    while (mid <= last)
    {
        switch (arr[mid])
        {
        case 0:
            ++prev;
            swap(&arr[mid], &arr[prev]);
            ++mid;
            break;
        case 1:
            ++mid;
            break;
        case 2:
            swap(&arr[mid], &arr[last]);
            --last;
            break;
        }
    }

    cout<<"the sorted array by dnf is: "<<endl;

    //print
    for (int i = 0; i < size; i++){
        cout << arr[i] << ' ';
    }
}
