/*
Objective: Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14". 
Time Complexity: O(N)
Space Complexity: O(N)
*/
#include <iostream>
using namespace std;
#include <iostream>

using namespace std;

#include <bits/stdc++.h>

void help(char input[], int size)
{
    if(size==0) //base case
        return;
    if(input[0]=='p')
    {
        if(input[1]=='i')
        {
            for(int i=size;i>1;i--)
            {
                input[i+2]=input[i];
            }
            input[0]='3';
            input[1]='.';
            input[2]='1';
            input[3]='4';
            size =size +2;

        }
    }

    help(input+1,size-1);//recursive call
}
int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}\