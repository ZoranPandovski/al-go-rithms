import java.util.Scanner;

/* class node*/
class Node
{
	protected int data;
	protected Node link;

	  /*  constructor  */
	public Node()
	{
		link=null;
		data=0;
	}

	 /*  Constructor  */
	public Node(int d, Node n)
	{
		data=d;
		link=n;
	}

	 /*  Function to set link to next node  */
	public void setLink(Node n)
	{
		link=n;
	}

	 /*  Funtion to set data to curent node  */
	 public void setData(int d)
	 {
		 data=d;
	 }

	  /*  Function to get link to next node  */
	  public Node getLink(){
		  return link;
	  }

	  /*  Function to get data to next node  */
	  public int getData(){
		  return data;
	  }

}

  /* Class LinkedList  */
  class LinkedList
  {
	  protected Node start;
	  protected Node end;
	  protected int size;

	    /*  Constructor  */
		public LinkedList()
		{
			start=null;
			end=null;
			size=0;
		}

		/*  Function to check if list is empty  */
		public boolean isEmpty(){
			return start == null;
		}

		/*  Function to get size of list  */
		public int getSize()
		{
			return size;
		}

		/*  Function to insert an element at begining  */

		public void insertAtStart(int val)
		{
			Node nptr = new Node(val,null);
			size++;
			if(start == null)
			{
				start=nptr;
				end=start;
			}else
			{
				nptr.setLink(start);
				start=nptr;
			}
		}

		/*  Function to insert an element at end  */
		public void insertAtEnd(int val)
		{
			Node nptr = new Node(val,null);
			size++;
			if(start == null)
			{
				start = nptr;
				end = start;
			}else
			{
				end.setLink(nptr);
				end = nptr;
			}
		}

		/*  function to insert an element at position  */
		public void insertAtPos(int val,int pos)
		{
			Node nptr = new Node(val,null);
			Node ptr = start;
			pos = pos-1;
			for(int i=1; i<size; i++)
			{
				if(i == pos){
					Node tmp = ptr.getLink();
					ptr.setLink(nptr);
					nptr.setLink(tmp);
					break;
				}
				ptr = ptr.getLink();
			}
			size++;
		}

		/*  functon to delete an element  at position  */

		public void deleteAtPos(int pos)
		{
			if(pos == 1)
			{
				start = start.getLink();
				size--;
				return ;
			}
			if(pos == size)
			{
				Node s = start;
				Node t = start;
				while(s != end)
				{
					t = s;
					s = s.getLink();
				}
				end = t;
				end.setLink(null);
				size--;
				return;
			}
			Node ptr=start;
			pos = pos-1;
			for(int i=1; i<size-1;i++)
			{
				if(i == pos)
				{
					Node tmp = ptr.getLink();
					tmp = tmp.getLink();
					ptr.setLink(tmp);
					break;
				}
				ptr = ptr.getLink();
			}
			size--;
		}

		/*  funcion to display element  */
		public void display()
		{
			System.out.print("\nSingle Linked List = ");
			if(size == 0)
			{
				System.out.print("\nempty\n");
				return;
			}
			if(start.getLink() == null)
			{
				System.out.println(start.getData());
				return;
			}
			Node ptr = start;
			System.out.print(start.getData()+"->");
			ptr = ptr.getLink();
			while(ptr.getLink() != null){
				System.out.print(ptr.getData()+"->");
				ptr = ptr.getLink();

			}
		System.out.print(ptr.getData()+"\n");
		}
  }

  public class SingleLinkedList{
	  public static void main(String args[]){

		 Scanner sc = new Scanner(System.in);

		 /*Creatint a object of class Linked list*/
		 LinkedList ll = new LinkedList();
		 System.out.println("singly linked list Test\n");
		  char ch;

		   /*perform list operations*/
		   do{
			   	 System.out.println("\nsingly linked list Operations\n");
		 		 System.out.println("1. Insert at begning");
				 System.out.println("2. Insert at end");
				 System.out.println("3. Insert at position");
				 System.out.println("4. Delete at position");
				 System.out.println("5. check empty");
				 System.out.println("6. get size");
				 int choice = sc.nextInt();

				 switch(choice){
					 case 1: System.out.println("Enter integer element to Insert ");
					 ll.insertAtStart(sc.nextInt());
					 break;

					 case 2: System.out.println("Enter integer element to Insert ");
					 ll.insertAtEnd(sc.nextInt());
					 break;

					 case 3: System.out.println("Enter integer element to Insert ");
					 int num= sc.nextInt();
					 System.out.println("Enter position ");
					 int pos = sc.nextInt();
					 if(pos<=1 || pos>ll.getSize()){
						 System.out.println("Invalid position\n");
					 }else{
						 ll.insertAtPos(num,pos);
					 }

					 break;
					 case 4: System.out.println("Enter position ");
					 int p = sc.nextInt();
					 if(p<1 || p>ll.getSize()){
						 System.out.println("Invalid position\n");
					 }else{
						 ll.deleteAtPos(p);
					 }
					 break;

					 case 5: System.out.println("Empty status = "+ll.isEmpty());
					 break;

					 case 6: System.out.println("Size = "+ll.getSize() + "\n");
					 break;

					 default: System.out.println("Wrong entry\n");
					 break;
				 }
				 /*Display List*/
				 ll.display();
					System.out.println("\n Do you want to continue (Type y or n)");
					ch = sc.next().charAt(0);
		   }while(ch == 'Y' || ch == 'y');

	  }
  }