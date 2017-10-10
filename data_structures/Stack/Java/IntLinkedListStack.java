public class IntLinkedListStack {
	Node top;
	int size;
	public IntLinkedListStack()
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
