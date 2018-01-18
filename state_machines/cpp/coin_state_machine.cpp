/*
This machine returns a quarter when exactly 25 cents are inserted. The machine does so through an FSM (finite state machine), 
and does retain any memory of which coins were inserted previously. 
*/

#include <iostream>

using namespace std;

//Declare state as a global variable.
int state = 0;

int main()
{
	while (state != 25)
	{
		//Ask the user to input a coin.
		cout << "Your balance is " << state << endl;
		cout << "Please insert a coin (penny, nickel, dime, quarter)" << endl;

		string coin; 
		cin >> coin;

		//Account for different coins entered and add corresponding value.
		if (coin == "penny")
			state += 1;
		
		else if(coin == "nickel") 
				state += 5;
		
		else if(coin == "dime") 
				state += 10;
		
		else if(coin == "quarter") 
				state += 25;
		
		//If an unrecognized coin is entered.
		else
			cout << "Sorry, this is not a coin" << endl;
	}

	cout << "Thanks, here's your quarter" << endl;

	return 0;
}