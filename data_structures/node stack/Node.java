// anode class for a singly linked list

public class Node
{
	public Object element;
	public Node next;
	
	// constructor
	public Node()
	{
		element = null;
		next = null;
	}
	
	public Node(Object e, Node n)
	{
		element = e;
		next = n;
	}
}