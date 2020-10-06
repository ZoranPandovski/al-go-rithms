// Java program for reversing the linked list 
  
public class LinkedList { 
  
    static Node head; 
    static Node tail;    

    static class Node { 
  
        int data; 
        Node next; 
  
        Node(int d, Node n) { 
            data = d; 
          //  next = null; 
            next = n; 

        } 
    }
    
  //addNode() will add a new node to the list    
    public static void addNode(int data) {    
        //Create a new node    
        Node newNode = new Node(data,null);    
            
        //Checks if the list is empty    
        if(head == null) {    
            //If list is empty, both head and tail will point to new node    
            head = newNode;    
            tail = newNode;    
        }    
        else {    
            //newNode will be added after tail such that tail's next will point to newNode    
            tail.next = newNode; 
           
            //newNode will become new tail of the list    
            tail = newNode;    
        }
    }
    
    
    
    /* Function to count the linked list */
    public static int countNode (Node head) {
    	
    	int count = 0;
    	for(Node n = head; n!=null; n=n.next) {
    		count++;
    	}
    	return count;
    }
    
    
    /* Function for getting a specific Node from the linked list */
    public static Node nodeAt(int index) { //returns Node
    	int i = 0;
    	int size = countNode(head)-1;
    	
    	for(Node n = head; n!= null; n=n.next) {
    		if(index<0 || index >= size) {
    			return null;
    		}
    		if(i == index) {
    			return n; // n.data for returning the value only
    			          // then change the func to:  int nodeAt()
    		}
    		i++;
    	}
    	
    	return null;
    }
    
    /* Function for insertion of a Node in the linked list */
    public static Node insert(int element,int index) { 
    	Node newNode = new Node(element,null);
    	//if head reference changes
    	if(index == 0) {
    		newNode.next = head; //changing the ref
    		head = newNode; //replacing the whole node
    	}else {
    		//get the predecessor node first
    		Node pred = nodeAt(index-1);
    		newNode.next = pred.next;
    		pred.next = newNode;
    	}
    	return head;
    }
    
  //function will delete a new node to the list    
    public static Node remove(int index) {    
        //reference to the remove node    
        Node removedNode = null;    
        
        //if head ref changes
        if(index == 0) {
        	removedNode = head;
        	head = head.next;
        }else {
        	//get the predecessor node first
        	Node pred = nodeAt(index-1);
        	removedNode = pred.next;
        	pred.next = removedNode.next;
        }
        
        //helping the GC(garbase collector)
        removedNode.data = -100; //null in theo
        removedNode.next = null;
        
        return head; //sending reference head of the updated list
        
    }
    
    /* Function for getting value from a specific Node in the linked list */
    public static int nodeAtVal(int index) { //returns Node / getNode()
    	int i = 0;
    	int size = countNode(head)-1;
    	
    	for(Node n = head; n!= null; n=n.next) {
    		if(index<0 || index > size) {
    			return (Integer) null;
    		}
    		if(i == index) {
    			return n.data; // n.data for returning the value only
    			          // then change the func to:  int nodeAt()
    		}
    		i++;
    	}
    	
    	return (Integer) null; //index out of bounds
    }
    
    
    /*Function to set a given value in a Node*/
    public static int set(int value,int index) {
    	Node node = nodeAt(index);
    	if(node == null) {
    		return (Integer) null;
    	}
    	else {
    		int oldElem = node.data; //keeping the old data in a variable
    		node.data = value; //setting the value
    		return oldElem;
    	}
    }
    
    
    /*Function for searching the index of a given element/value in a list*/
    public static int indexOf(int value) {
      int index = 0;
      for(Node n = head; n!= null ; n = n.next) {
    	  if(n.data == value) {
    		  return index;
    	  }
    	  index++;
      }
      return -1;
    }
  
    /* Function to reverse the linked list */
    public static Node reverseList(Node head) { 
    	
    	Node revHead = null;
    	for( Node n = head; n!= null; n = n.next) {
    		Node newNode = new Node(n.data,null);
    		//add the node's copy to the beginning of the reversed list
    		
    		newNode.next = revHead;
    		revHead = newNode;
    		
    	}
    	return revHead;
    } 
    
    /* Function to copy the linked list */
    public static Node copyList() {
    	Node copyHead = new Node(head.data, null);
    	Node copyTail = copyHead;
    	
    	for(Node n = head.next; n!= null; n=n.next) {
    		Node newNode = new Node(n.data,null);
    		copyTail.next = newNode;
    		copyTail = newNode;
    	}
    	return copyHead;
    }
    
  
    // prints content of double linked list 
    void printList(Node n) // Node n = head is being passed
    { 
       /* while (n != null) { 
            System.out.print(n.data + " "); 
            n = n.next; 
        } */
    	
    	for(; n!= null; n=n.next) {
    		System.out.print(n.data + " ");
    	}
    } 
  
    public static void main(String[] args) 
    { 
        LinkedList list = new LinkedList(); 
      /*list.head = new Node(85); 
        list.head.next = new Node(15); 
        list.head.next.next = new Node(4); 
        list.head.next.next.next = new Node(20);  
        
        list.head = new Node(85,null); 
        list.head.next = new Node(15,null); 
        list.head.next.next = new Node(200,null); 
        list.head.next.next.next = new Node(20,null);
        list.head.next.next.next.next = new Node(60,null); */
        
        list.addNode(85);
        list.addNode(15);
        list.addNode(4);
        list.addNode(20);

        
        System.out.println("Number of nodes in the Linked list: "+ list.countNode(head));
        list.set(4, 2);
        System.out.println("Value is "+list.nodeAtVal(2)); 

  
        System.out.print("Given Linked list: "); 
        for(Node n = head; n!= null; n=n.next) {
    		System.out.print(n.data + " ");
    	}
        
        System.out.println(""); 
        list.insert(90, 0);
        System.out.println("After insertion Given Linked list: "); 
        for(Node n = head; n!= null; n=n.next) {
    		System.out.print(n.data + " ");
    	}
        
        System.out.println(""); 
        System.out.print("Reversed linked list: "); 
        list.printList(list.reverseList(head)); 
        
        System.out.println(""); 
        System.out.println("Index search result "+list.indexOf(20));
        
        list.remove(2);
        list.printList(list.copyList()); 

        

    } 
}
