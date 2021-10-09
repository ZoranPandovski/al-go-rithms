//Testing the Stack

public class NodeTest
{
	public static void main(String[]args)
	{
		int N=10;
		LinkStack as = new LinkStack();
		
		System.out.println("PUSH Operations");
		for (int i=0; i<N; i++)
		{
			as.push(i+11);
			System.out.print("Item in top:" + as.top());
			System.out.println("Number of items in the Stack:" + as.size());
		}
		
		System.out.println("POP Operations");
		for (int i=0; i<N; i++)
		{
			System.out.print("Pop Element:" + as.pop());
			System.out.print("Number of items in the Stack:" + as.size());
			System.out.println("NOW, item in top:" + as.top());
		}
	}
}