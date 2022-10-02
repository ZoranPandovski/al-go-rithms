// C# program to sort a Stack using recursion
// Note that here predefined Stack class is used
// for stack operation
using System;
using System.Collections;

public class GFG
{
	// Recursive Method to insert an item x in sorted way
	static void sortedInsert(Stack s, int x)
	{
		// Base case: Either stack is empty or
		// newly inserted item is greater than top
		// (more than all existing)
		if (s.Count == 0 || x > (int)s.Peek()) {
			s.Push(x);
			return;
		}

		// If top is greater, remove
		// the top item and recur
		int temp = (int)s.Peek();
		s.Pop();
		sortedInsert(s, x);

		// Put back the top item removed earlier
		s.Push(temp);
	}

	// Method to sort stack
	static void sortStack(Stack s)
	{
		// If stack is not empty
		if (s.Count > 0) {
			// Remove the top item
			int x = (int)s.Peek();
			s.Pop();

			// Sort remaining stack
			sortStack(s);

			// Push the top item back in sorted stack
			sortedInsert(s, x);
		}
	}

	// Utility Method to print contents of stack
	static void printStack(Stack s)
	{
		foreach(int c in s) { Console.Write(c + " "); }
	}

	// Driver code
	public static void Main(String[] args)
	{
		Stack s = new Stack();
		s.Push(30);
		s.Push(-5);
		s.Push(18);
		s.Push(14);
		s.Push(-3);

		Console.WriteLine(
			"Stack elements before sorting: ");
		printStack(s);

		sortStack(s);

		Console.WriteLine(
			" \n\nStack elements after sorting:");
		printStack(s);
	}
}

