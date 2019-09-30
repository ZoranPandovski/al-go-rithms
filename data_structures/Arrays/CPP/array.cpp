#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int row,col,i,j;
    cout<<"Enter size of row and column: ";
    cin>>row>>col;
    //dynamic declaration of 2d array
    int **arr=new int*[row];
    for(i=0;i<row;i++)
        arr[i]=new int[col];
    cout<<"Enter elements of matrices(row wise)"<<endl;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            cin>>arr[i][j];
    cout<<"Displaying matrix"<<endl;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            cout<<arr[i][j]<<"  ";
        cout<<endl;
    }
    getch();
    return 0;
}
