import java.util.Scanner;
class IntegerLinkedListStack {
	Node top;
	int size;
	public IntegerLinkedListStack()
	{
		top = null;
		size = 0;
	}
	
	public void push(int n)
	{
		Node node = new Node(n);
		if(top!=null)
			node.next = top;
		top = node;
		++size;
	}
	public int pop()
	{
		if(!isEmpty())
		{
			Node focus = top;
			top = top.next;
			--size;
			return focus.getValue();
			//focus is now gone
		}
		return 0;
	}
	public int peek()
	{
		if(!isEmpty())
			return top.getValue();
		return 0;
	}
	public int size()
	{
		return size;
	}
	public boolean isEmpty()
	{
		return size==0;
	}
	public void clear()
	{
		size = 0;
		top = null;
		//all other nodes are lost
	}
	
}
class Node
{
	Node next;
	int value;
	Node(int n)
	{
		value = n;
		next = null;
	}
	public int getValue(){return value;}
}

public class IntLinkedListStack {
	public static void main(String[] args)
	{
		Scanner kb = new Scanner(System.in);
		IntegerLinkedListStack stack = new IntegerLinkedListStack();
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
