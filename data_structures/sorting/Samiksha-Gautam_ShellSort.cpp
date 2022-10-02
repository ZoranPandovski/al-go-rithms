/*Shell sort is a generalized version of the insertion sort 
algorithm. It first sorts elements that are far apart from
each other and successively reduces the interval
between the elements to be sorted.*/

#include  <iostream>
using namespace std;
 
int shellSort(int arr[], int n)
{
    for (int g = n/2; g > 0; g /= 2)
    {
        for (int i = g; i < n; i += 1)
        {
            int temp = arr[i];
            int j;           
            for (j = i; j >= g && arr[j - g] > temp; j -= g)
                arr[j] = arr[j - g];
                arr[j] = temp;
        }
    }
    return 0;
}
 
void print(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
 
int main()
{
    cout << "Enter the number of elements in the array \n";
    int n;
    cin >> n;
    o
     int arr[n] ;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout << "Array before sorting: \n";
    print(arr, n);
 
    shellSort(arr, n);
 
    cout << "\nArray after sorting: \n";
    print(arr, n);
 
}

/*
Input :

Enter the number of elements in the array 
5  
Enter the elements of the array 
12 34 54 2 3

Output :

Array before sorting: 
12 34 54 2 3 
Array after sorting: 
2 3 12 34 54 

*/
