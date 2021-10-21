/**       Author: Ajaysinh Rajput         **/

//        Josephus Problem            //

/*
 Problem: There are n people standing in a circle waiting to be executed. The counting out begins at 
 	  some point in the circle and proceeds around the circle in a fixed direction. In each step,
	  a certain number of people are skipped and the next person is executed. The elimination 
	  proceeds around the circle (which is becoming smaller and smaller as the executed people
	  are removed), until only the last person remains, who is given freedom. Given the total 
	  number of persons n and a number k which indicates that k-1 persons are skipped and kth
	  person is killed in circle. The task is to choose the place in the initial circle so that
	  you are the last one remaining and so survive.
 
 Solution: Recursive Approach as following:
           josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
           josephus(1, k) = 1
*/



#include <iostream>
using namespace std;


// Recursive function to choose right position
int SafePosition(int n, int k)
{

    /* we call SafePosition(n – 1, k) to get the position with n-1 
       persons. But the position returned by SafePosition(n – 1, k) will
       consider the position starting from k%n + 1. So, we must make
       adjustments to the position returned by SafePosition(n – 1, k). 
    */
	return (n==1)?1:(SafePosition(n - 1, k) + k - 1) % n + 1;

}


int main()
{

	int n,k;
	cout<<"\n Enter total no. of people: ";
	cin>>n;
	cout<<"\n Person to be killed: ";
	cin>>k;
    
	cout<<"\n Safe Position: "<<SafePosition(n,k)<<'\n';

    return 0;

}
