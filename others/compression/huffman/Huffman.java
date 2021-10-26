//IMPLEMENTATION OF A HUFFMAN ENCODER


import java.util.Scanner;
import java.util.Vector;
import java.util.Comparator; 
  
//class node
class huffman_node 
{ 
	//frequency
    int frequency; 
    
   //character
    char character; 
    
    huffman_node left; 
    huffman_node right; 
    
    //constructor
    huffman_node()
    {
    	frequency=0;
    	character=' ';
    	left=null;
    	right=null;
    }
} 
  
//comparator class to compare data of nodes
class MyComparator implements Comparator<huffman_node>  
{
    public int compare(huffman_node x1, huffman_node y1) 
    { 
         return x1.frequency - y1.frequency; 
    } 
} 

// priority queue using heaps
class priority_queue 
{
	//vector to store the nodes
	 Vector<huffman_node> v2; 
	
	// constructor
	public priority_queue(int number1, MyComparator comp1)
	{
		v2 = new Vector();
	}

		// return parent 
	 int parent(int h)
	{
		// if i is  root 
		if (h == 0) 
		{
			return 0;
		}
		return (h-1)/2;
	}



	 
}

public class Huffman { 
  
    // recursive function to print
  public static void printCode(huffman_node root, String s) 
   { 
  
      if (root.left  == null&& root.right  == null && 
    		  Character.isLetter(root.character)) 
      { 
  
        System.out.println("   "+ root.character +"      |      "+ root.frequency 
        		+ "        |     " + s); 
        return; 
       } 
  
        // if left add "0" 
        printCode(root.left, s + "0"); 
        
       // if right add"1" 
        printCode(root.right, s + "1");  
    } 
  
    // main function 
    public static void main(String[] args) 
    { 
        Scanner s = new Scanner(System.in); 
        
        // variable to store the size of the array
        int n = 0;  
        
        int choice=0;
        
        do {
        	System.out.println("-------------------------------------HUFFMAN ENCODER----------"
        			+ "------------------------------------");
        	System.out.println("PRESS 1 FOR HUFFMAN ENCODER");
        	System.out.println("PRESS 2 FOR EXIT");
        	System.out.println("---------------------------------------------------------"
        			+ "-------------------------------------------");
        	System.out.println("  ");
        	choice=s.nextInt();
        	switch(choice) 
        	{
        	case 1:
                System.out.println("ENTER THE NUMBER OF CHARACTERS :");
    	  do {
    	    n = s.nextInt();
    	    if(n<0) 
    	    { 
    	    	//validation
    		 System.out.println("THE VALUE CANNOT BE NEGATIVE. TRY AGAIN"); 
    	    }
    	   }while(n<0);
    	
    	System.out.println("  ");
    	
    	//array to store characters
    	char[] arr1 = new char[n];
    	
    	//array to store frequencies    	
    	int[] freq1 = new int[n]; 
    	
    	System.out.println("ENTER THE  CHARACTERS AND FREQUENCIES :");
    	
        for(int i1=0; i1<n ;i1++) 
        {
        	System.out.println("ENTER THE CHARACTER NUMBER "+(i1+1)+"  : ");
        	arr1[i1]=s.next().charAt(0);
        	System.out.println("ENTER THE FREQUENCY OF THe CHARACTER '"+ 
        	arr1[i1]+"' :");
        	freq1[i1]=s.nextInt();
        }
        
        System.out.println("  ");
        
        System.out.print("CHARACTERS ARE : { "); 
        for(int i1=0; i1<n ;i1++) 
        {
        	System.out.print(arr1[i1]);
        	if(i1!=n-1)
        	{
        		System.out.print(" , ");
        	}
        }
        System.out.print(" }");
        System.out.println(" ");       
 
        System.out.println("  ");
        System.out.print("FREQUENCIES ARE : { "); 
        for(int i1=0; i1<n ;i1++) 
        {
        	System.out.print(freq1[i1]+"");
        	if(i1!=n-1)
        	{
        		System.out.print(" , ");
        	}
        }
        System.out.print(" }");
        System.out.println(" ");
        System.out.println(" ");
        
        System.out.println("____________________________________________");
        System.out.println("CHARACTER |  FREQUENCY    |  HUFFMAN CODE  ");
        
      //create new object of class priority_queue
        priority_queue q  = new priority_queue(n, new MyComparator()); 
  
        for (int i = 0; i < n; i++) 
        { 
        	//create new object of class huffman_node
            huffman_node hn = new huffman_node(); 
  
            hn.character = arr1[i]; 
            hn.frequency = freq1[i]; 
  
            hn.left = null; 
            hn.right = null; 
 
          //add the nodes in the priority queue
            q.add(hn);  
        } 
  
      //Initialize root to null
        huffman_node root = null; 
  
        //while loop when it is queue size is greater than one
        while (q.size() > 1) 
        { 
  
            huffman_node first = q.peek(); //to find the first element
            q.poll();                //remove
  
            huffman_node second = q.peek(); //to find the first element
            q.poll();                 //remove
  
            huffman_node temp = new huffman_node(); 
  
            //add the data of 2 nodes
            temp.frequency = first.frequency + second.frequency;
            temp.character = '-'; 
              
            temp.left = first; 
  
            temp.right = second; 
  
            root = temp; 
        
          //add in the queue
            q.add(temp);  
        } 
  
        // print the codes by traversing the tree 
        printCode(root, " "); 
        System.out.println("____________________________________________");
        System.out.println(" ");
        break;
        
        case 2:
        	System.out.println("THANK YOU !");
        	System.out.println("  ");
        	break;
        	
        default:
        	System.out.println("WRONG CHOICE ! TRY AGAIN");
        	System.out.println(" ");
            break;
        	
        	}
        	}while(choice!=2);
    }
} 


/*
 OUTPUT :
 
-------------------------------------HUFFMAN ENCODER----------------------------------------------
PRESS 1 FOR HUFFMAN ENCODER
PRESS 2 FOR EXIT
----------------------------------------------------------------------------------------------------
  
1
ENTER THE NUMBER OF CHARACTERS :
-8
THE VALUE CANNOT BE NEGATIVE. TRY AGAIN
6
  
ENTER THE  CHARACTERS AND FREQUENCIES :
ENTER THE CHARACTER NUMBER 1  : 
a
ENTER THE FREQUENCY OF THe CHARACTER 'a' :
5
ENTER THE CHARACTER NUMBER 2  : 
b
ENTER THE FREQUENCY OF THe CHARACTER 'b' :
9
ENTER THE CHARACTER NUMBER 3  : 
c
ENTER THE FREQUENCY OF THe CHARACTER 'c' :
12
ENTER THE CHARACTER NUMBER 4  : 
d
ENTER THE FREQUENCY OF THe CHARACTER 'd' :
13
ENTER THE CHARACTER NUMBER 5  : 
e
ENTER THE FREQUENCY OF THe CHARACTER 'e' :
16
ENTER THE CHARACTER NUMBER 6  : 
f
ENTER THE FREQUENCY OF THe CHARACTER 'f' :
45
  
CHARACTERS ARE : { a , b , c , d , e , f } 
  
FREQUENCIES ARE : { 5 , 9 , 12 , 13 , 16 , 45 } 
 
____________________________________________
CHARACTER |  FREQUENCY     |  HUFFMAN CODE  
   f      |      45        |      0
   c      |      12        |      100
   d      |      13        |      101
   a      |      5         |      1100
   b      |      9         |      1101
   e      |      16        |      111
____________________________________________
 
-------------------------------------HUFFMAN ENCODER----------------------------------------------
PRESS 1 FOR HUFFMAN ENCODER
PRESS 2 FOR EXIT
----------------------------------------------------------------------------------------------------
  
1
ENTER THE NUMBER OF CHARACTERS :
5
  
ENTER THE  CHARACTERS AND FREQUENCIES :
ENTER THE CHARACTER NUMBER 1  : 
t
ENTER THE FREQUENCY OF THe CHARACTER 't' :
6
ENTER THE CHARACTER NUMBER 2  : 
h
ENTER THE FREQUENCY OF THe CHARACTER 'h' :
8
ENTER THE CHARACTER NUMBER 3  : 
m
ENTER THE FREQUENCY OF THe CHARACTER 'm' :
1
ENTER THE CHARACTER NUMBER 4  : 
z
ENTER THE FREQUENCY OF THe CHARACTER 'z' :
3
ENTER THE CHARACTER NUMBER 5  : 
c
ENTER THE FREQUENCY OF THe CHARACTER 'c' :
4
  
CHARACTERS ARE : { t , h , m , z , c } 
  
FREQUENCIES ARE : { 6 , 8 , 1 , 3 , 4 } 
 
____________________________________________
CHARACTER |  FREQUENCY    |  HUFFMAN CODE  
   h      |      8        |      0
   t      |      6        |      10
   c      |      4        |      110
   m      |      1        |      1110
   z      |      3        |      1111
____________________________________________
 
-------------------------------------HUFFMAN ENCODER----------------------------------------------
PRESS 1 FOR HUFFMAN ENCODER
PRESS 2 FOR EXIT
----------------------------------------------------------------------------------------------------
  
7
WRONG CHOICE ! TRY AGAIN
 
-------------------------------------HUFFMAN ENCODER----------------------------------------------
PRESS 1 FOR HUFFMAN ENCODER
PRESS 2 FOR EXIT
----------------------------------------------------------------------------------------------------
  
2
THANK YOU !
  

  

*/
 
  
