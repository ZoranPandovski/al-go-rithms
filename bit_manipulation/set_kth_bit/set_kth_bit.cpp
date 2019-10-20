#include<iostream>
using namespace std

int set_kth_bit(int N,int k)
{
        int a;
        a=1<<(k-1)        //1 is right-shifted (k-1) times to set the kth bit '1', while the remaining bits remain unset. 
        N=N|a;            // Using the bitwise OR operator the kth bit of 'N' is set.
        return N;
}
int main()
{
        int N,k;
        cout<<"ENTER THE NUMBER";
        cin>>N;
        cout<<"ENTER THE VALUE OF k";
        cin>>k;

        N=set_kth_bit(N);     /*function to compute the new value after setting the kth bit in binary representation of given number 'N'. 
                                Store the result back in 'N'.*/

        cout<<"After seting the bit the number becomes"<<N;
        return 0;
}

