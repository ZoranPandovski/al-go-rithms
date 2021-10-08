//interface Stack

public interface Stack
{
	//return number of elements in the stack
	public int size();
	
	//return whether the stack is empty
	public boolean isEmpty();
	
	//return top element in the stack
	public Object top() throws StackEmptyException;
	
	//remove the top element from the stack
	public Object pop() throws StackEmptyException;
	
}