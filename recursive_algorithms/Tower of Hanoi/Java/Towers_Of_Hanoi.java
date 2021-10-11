/*
	QUESTION:

	Tower of Hanoi is a mathematical puzzle where we have three rods and n disks.
	The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules: 

    1. Only one disk can be moved at a time.
    2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
    3. No disk may be placed on top of a smaller disk.

    APPROACH:

    Take an example for 2 disks :
	Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.

	Step 1 : Shift first disk from 'A' to 'B'.
	Step 2 : Shift second disk from 'A' to 'C'.
	Step 3 : Shift first disk from 'B' to 'C'.

	The pattern here is :
	Shift 'n-1' disks from 'A' to 'B'.
	Shift last disk from 'A' to 'C'.
	Shift 'n-1' disks from 'B' to 'C'.

	NOTE: For any N number of discs the number of steps taken can be given by the formula,

		  Number of steps = 2^N -1 discs.
*/



public class Towers_Of_Hanoi
{

	public static void main(String[] args)
	{
		towersOfHanoi(3, 'A', 'B', 'C');
	}

	public static int steps = 1; // A steps counter to print the nth step.

	public static void towersOfHanoi(int number_of_disc, char from, char auxiliary, char to)
	{
		if(number_of_disc == 1)
		{
			System.out.println((steps++) + ". Moving disc from " + from + " to " + to);
		}
		else
		{
			towersOfHanoi(number_of_disc-1, from, to, auxiliary);

			System.out.println((steps++) + ". Moving disc from " + from + " to " + to);

			towersOfHanoi(number_of_disc-1, auxiliary, from, to);
		}
	}
}