/// ZERO ONE KNAPSACK
/// AUTHOR: SHAHiDCSEKU
/// DATE: 11:45 PM 9/29/2016


#include<iostream>
#include<fstream>
using namespace std;

struct Item{
int weight;
int value;
};
Item itemArray[25];
int arr[25][25] = {0};

int main()
{
    ofstream file("Output.txt");
    int test;
    int maxWeight;
    cout<<"How many Items ?\n";
    cin>> test;
    cout<<"Enter Item weight and Item value:\n";
    for(int t=1;t<=test;t++)
    {
        cin>> itemArray[t].weight;
        cin>>itemArray[t].value;
    }
    cout<<"Enter maximum weight:\n";
    cin>>maxWeight;

    for(int j=0;j<=maxWeight;j++)
    {
        if(itemArray[0].weight<=j)
       {
            arr[0][j] = itemArray[0].value;
       }
    }
    for(int i=1;i<=test;i++)
    {
        for(int j=1;j<=maxWeight;j++)
        {
            if(itemArray[i].weight<=j)
            {
                arr[i][j] = max(arr[i-1][j],(itemArray[i].value)+arr[i-1][j-(itemArray[i].weight)]);
            }
            else
            {
                arr[i][j] = arr[i-1][j];
            }
        }
    }
        for(int i=0;i<=test;i++)
    {
        for(int j=0;j<=maxWeight;j++)
        {
            file<<arr[i][j]<<" ";
        }
        file<<endl;
    }

    cout<<"Outputs are written in file successfully !";


}
