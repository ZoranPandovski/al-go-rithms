import java.util.Scanner;
public class Main {

	public static void main(String[] args)
	{
		Scanner kb = new Scanner(System.in);
		System.out.println("Input: \n"
				+ "1. Do a demo for an integer stack utilizing an array\n"
				+ "2. Do a demo for an integer stack utilizing a linked list");
		switch(kb.nextInt())
		{
			case 1:
				intArrayStackDemo(kb);//Program terminates within this function
				break;
			case 2:
				intLinkedListStackDemo(kb);//Program terminates within this function
				break;
			default:
				System.out.println("Invalid selection");
				kb.close();
				break;
		}
	}
	public static void intArrayStackDemo(Scanner kb)
	{
		System.out.println("Input a number for how big you want your integer array stack to be");
		IntArrayStack stack = new IntArrayStack(kb.nextInt());
		while(true)
		{
			System.out.println("Please select a valid number for the operation.\n"
					+ "1. Push a number onto the stack\n"
					+ "2. Pop a number off the stack\n"
					+ "3. Peek at the top of the stack\n"
					+ "4. Get the amount of items in the stack\n"
					+ "5. Check if the stack is empty\n"
					+ "6. Check if the stack is full\n"
					+ "7. Empty the stack\n"
					+ "8. Exit");
			switch(kb.nextInt())
			{
				case 1:
						System.out.println("What integer would you like pushed onto the stack");
						if(stack.push(kb.nextInt()))
							System.out.println("Integer susccesfully pushed");
						else
							System.out.println("Can't push integer to stack since the stack is full");
					break;
				case 2:
						if(stack.isEmpty())
							System.out.println("No integers to pop since the stack is empty");
						else
							System.out.println(stack.pop()+" was popped off the stack");
					break;
				case 3:
						if(stack.isEmpty())
							System.out.println("No integers to peek at since the stack is empty");
						else
							System.out.println(stack.peek()+" is at the top of the stack");
					break;
				case 4:
						System.out.println("There are "+stack.size()+" integers on the stack");
					break;
				case 5:
						if(stack.isEmpty())
							System.out.println("The stack is empty");
						else
							System.out.println("The stack is not empty");
					break;
				case 6:
						if(stack.isFull())
							System.out.println("The stack is full");
						else
							System.out.println("The stack is not full");
					break;
				case 7:
						stack.clear();
						System.out.println("The stack has been emptied");
					break;
				case 8:
					kb.close();
					System.exit(0);//Program terminates
					break;
			}
		}
	}
	public static void intLinkedListStackDemo(Scanner kb)
	{
		IntLinkedListStack stack = new IntLinkedListStack();
		while(true)
		{
			System.out.println("Please select a valid number for the operation.\n"
					+ "1. Push a number onto the stack\n"
					+ "2. Pop a number off the stack\n"
					+ "3. Peek at the top of the stack\n"
					+ "4. Get the amount of items in the stack\n"
					+ "5. Check if the stack is empty\n"
					+ "6. Empty the stack\n"
					+ "7. Exit");
			switch(kb.nextInt())
			{
				case 1:
						System.out.println("What integer would you like pushed onto the stack");
						stack.push(kb.nextInt());
						System.out.println("Integer susccesfully pushed");
					break;
				case 2:
						if(stack.isEmpty())
							System.out.println("No integers to pop since the stack is empty");
						else
							System.out.println(stack.pop()+" was popped off the stack");
					break;
				case 3:
						if(stack.isEmpty())
							System.out.println("No integers to peek at since the stack is empty");
						else
							System.out.println(stack.peek()+" is at the top of the stack");
					break;
				case 4:
						System.out.println("There are "+stack.size()+" integers on the stack");
					break;
				case 5:
						if(stack.isEmpty())
							System.out.println("The stack is empty");
						else
							System.out.println("The stack is not empty");
					break;
				case 6:
						stack.clear();
						System.out.println("The stack has been emptied");
					break;
				case 7:
					kb.close();
					System.exit(0);//Program terminates
					break;
			}
		}
	}

}
