
/*Monty Hall was a popular game show host on American television. Assume , you are a contestant from the studio audience. He shows you three doors,Door #1, Door #2, and Door #3. Hidden behind one door is a brand new car, and behind each of the other two doors is a goat.

Monty asks you to pick a door. Of course, you want to pick the right door and win the car. Monty knows which door hides the car. After you’ve picked a door, he opens one of the other doors and shows you a goat. Monty then offers you a chance to stay with the door you originally picked, or you can switch your choice to the remaining third door. Would staying or switching be better?

The simulation: C++ program to simulate the above scenario. The program does the following:

Randomly pick a door to hide the car.
Acting as you, randomly pick a door as your first door choice.
Acting as Monty, open a door to reveal a goat. Since Monty (i.e., the program) knows which door hides the car: a. If your first door choice was correct, the other two doors each hides a goat. Monty randomly chooses one of the two doors to open. b. If your first door choice was incorrect (your door hides a goat), Monty opens the other door that hides a goat.
This leaves a third door to which you can switch as your second door choice. The program should keep track of whether you win by staying with your first door choice or if you win by switching to your second door choice.
The simulation is made to run 100 times.*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
typedef int Door;

const int SIMULATION_COUNT = 100;

/**
 * Suggested problem decomposition.
 * You do not have to use these function declarations.
 */

//Function Declarations
Door hideCar();
Door openDoor(Door firstChoiceDoor, Door carBehindDoor);
Door makeFirstChoice();
Door makeSecondChoice(Door firstDoor, Door openedDoor);
void simulate(int sequence, int& win1, int& win2);


/**
 * Main
 */
int main()
{
    int win1 = 0, win2 = 0;

    srand(time(NULL));  // seed the random number generator
    

    // Run the simulations.
    for (int i = 1; i <= SIMULATION_COUNT; i++) simulate(i, win1, win2);

    cout << endl;
    cout << setw(4) << win1 << " wins if stay with the first choice" << endl;
    cout << setw(4) << win2 << " wins if switch to the second choice" << endl;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    cout << endl;
    cout << "Win ratio of switch over stay: ";
    cout << static_cast<double>(win2)/win1 << endl;
}

/***** Complete this program. ****/

//Function Definitions
Door hideCar()
{
	  Door carBehindDoor = rand()%3 + 1;
	  return carBehindDoor;

}

Door makeFirstChoice()
{
    Door  firstChoiceDoor = rand()%3 + 1;
	return firstChoiceDoor;
}

Door openDoor(Door firstChoiceDoor, Door carBehindDoor)
{
	Door openedDoor;
	Door tempDoor = rand()%3 + 1;
	while((firstChoiceDoor == tempDoor)||(carBehindDoor == tempDoor))
	{
		tempDoor = rand()%3 + 1;
	}
	openedDoor = tempDoor;
	return openedDoor;


}



Door makeSecondChoice(Door firstDoor, Door openedDoor)
{

	Door secondChoice;
	Door tempDoor = rand()%3 + 1;
		while((openedDoor == tempDoor)||(firstDoor == tempDoor))
		{
			tempDoor = rand()%3 + 1;
		}
	secondChoice = tempDoor;
	return secondChoice;


}


void simulate(int sequence, int& win1, int& win2)
{

	Door carBehindDoor = hideCar();
	Door firstChoiceDoor = makeFirstChoice();
	Door openedDoor = openDoor(firstChoiceDoor,carBehindDoor);
	Door secondChoice = makeSecondChoice(firstChoiceDoor,openedDoor);


   string w1 ="";
   string w2 ="";
   
   if (firstChoiceDoor== carBehindDoor)
		{
			win1++;
			w1 = "Yes";

		}
	else if (secondChoice == carBehindDoor)
		{
			win2++;
			w2 = "Yes";
		}
		

	cout << sequence<<"\t"<< carBehindDoor <<"\t" <<firstChoiceDoor<<"\t"<<openedDoor<<"\t"<<secondChoice<<"\t"<<w1<<"\t"<<w2<<"\t"<<endl;
}

