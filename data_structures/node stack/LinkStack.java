// stack implementation using Linked List

public class LinkStack()
{
	private Node top;
	private int itemNumber;
	
	public LinkStack()
	{
		top = null;
		itemNumber = 0;
	}
	
	public int size ()
	{
		return itemNumber;
	}
	
	public boolean isEmpty()
	{
		return (itemNumber == 0);
	}
	
	public Object top() throws StackEmptyException
	{
		if (isEmpty())
			throw new StackEmptyException ("Stack is empty.");
		return top;
	}
	
	public void push (Object obj)
	{
		Node xNode = new Node;
		top = Node;
		itemNumber++;
	}
	
	public Object pop() throws StackEmptyException
	{
		if (isEmpty())
			throw new StackEmptyException ("No More POP! Stack is empty.");
		object elem = top.Node;
		top = new Node();
		itemNumber--;
		return elem;
	}
}