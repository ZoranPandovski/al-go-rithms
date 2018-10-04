import java.util.Scanner;
class integerArrayStack
{
    int[] theArrayStack;
    int nextAvailableSpot;//Is also the amount of items on the stack
    
    public integerArrayStack()
    {
    	this(20);
    }
    public integerArrayStack(int size)
    {
    	nextAvailableSpot = 0;
        theArrayStack = new int[size];
        theArrayStack[nextAvailableSpot] = 0;
    }
    
    public boolean push(int value)
    {
        if(isFull()){return false;}
        else
        {
            theArrayStack[nextAvailableSpot] = value;
            nextAvailableSpot++;
            return true;
        }
    }
    public int pop()
    {
        if(isEmpty()){return 0;}
        else
        {
            nextAvailableSpot--;
            return theArrayStack[nextAvailableSpot];
        }
    }
    public int peek()
    {
        if(isEmpty()){return 0;}
        else
            return theArrayStack[nextAvailableSpot-1];
    }
    public int size()
    {
        return nextAvailableSpot;
    }
    public boolean isEmpty()
    {
        if(nextAvailableSpot == 0){return true;}
        else{ return false;}
    }
    public boolean isFull()
    {
        if(nextAvailableSpot == theArrayStack.length){return true;}
        else{ return false;}
    }
    public void clear()
    {
        nextAvailableSpot = 0;
        theArrayStack[nextAvailableSpot] = 0;
    }
}
public class IntArrayStack {

	public static void main(String[] args)
	{
		Scanner kb = new Scanner(System.in);
		System.out.println("Input a number for how big you want your integer array stack to be");
		integerArrayStack stack = new integerArrayStack(kb.nextInt());
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

}
