#include <iostream>
#include <string>
using namespace std;

string doorStatus(bool);

const int NUMBEROFDOORS = 100;

int main()
{
	bool doors[NUMBEROFDOORS] = { false };

	for (int i = 0; i < NUMBEROFDOORS; i++){
		for (int j = i; j < NUMBEROFDOORS; j+= i + 1){
			doors[j] = !doors[j];
			
		}
			
	}

	for (int i = 0; i < NUMBEROFDOORS; i++){
		cout << "Door " << i + 1 << ": " << doorStatus(doors[i]);
	}
	

}

string doorStatus(bool door)
{
	if (door){
		return " is open\n";
	} else {
		return " is closed\n";
	}

}