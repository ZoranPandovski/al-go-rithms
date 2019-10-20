import java.util.*;
import java.io.*;

public class HundredDoors
{
	int numOfDoors = 100;
	boolean[] doors = new boolean[numOfDoors];

	public void openDoors()
	{
		for (int i = 0; i < numOfDoors; i++)
		{
			for (int j = i; j < numOfDoors; j += i + 1)
			{
				doors[j] = !doors[j];
			}
		}
	}

	public void printDoorStatus()
	{
		for (int i = 0; i < numOfDoors; i++)
		{
			System.out.println("Door " + (i+1) + ": " + ((doors[i]) ? "OPEN" : "CLOSED"));
		}
	}

	public static void main(String[] args)
	{
		HundredDoors hDoors = new HundredDoors();
		hDoors.openDoors();
		hDoors.printDoorStatus();
	}
} 
