import java.util.*;

class node
{
    int Data;
    node next;
};

class RemoveNthNodeFromList{

    private int size;
    private node Head;

    /**
     * Initialize an size and head of the SinglyLinkedList 
    */

    RemoveNthNodeFromList()
    {
        this.size = 0;
        this.Head = null;
    }

    /**
     * Function to display all elements of the SinglyLinkedList 
    */

    public void Display()
    {
        node temp = Head;

        while(temp != null)
        {
            System.out.print("|"+temp.Data+"|->");
            temp = temp.next;
        }
        System.out.print(" NULL\n");
    }

    /**
     * Function to insert elements into SinglyLinkedList 
    */

    public void Insert(int no)
    {
        node newn = new node();
        newn.Data = no;
        newn.next = null;

        if(Head == null)
        {
            Head = newn;
        }
        else
        {
            node temp = Head;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }
        size++;
    }

    /**
     * Function to delete first element from SinglyLinkedList 
    */

    public void DeleteFirst()
    {
        
        if(Head == null)
        {
            return;
        }
        else
        {
            Head = Head.next;
            System.gc();
        }
        size--;
    }

    /**
     * Function to delete last element from SinglyLinkedList 
    */

    public void DeleteLast()
    {
        node temp = Head;

        if(Head == null)
        {
            return;
        }
        else
        {
            while(temp.next.next != null)
            {
                temp = temp.next;
            }
            temp.next = null;
            System.gc();
        }
        size--;
    }

    /**
     * Function to delete element from any position in SinglyLinkedList 
    */

    public void DeleteAtPos(int ipos)
    {
        node Target = null;
        int i = 0;

        if((ipos < 1) || (ipos > size))
        {
            System.out.println("Invalid Position");
            return;
        }
        else if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == size)
        {
            DeleteLast();
        }
        else
        {
            node temp = Head;

            for(i = 1; i <= ipos - 1; i++)
            {
                temp = temp.next;
            }

            Target = temp.next.next;
            temp.next = Target;
            System.gc();

            size--;
        }
    }

    public static void main(String args[]) {
        int iRet = 0;
        int iValue = 1;
        int iChoice = 0;
        int ipos = 0;

        Scanner sc = new Scanner(System.in);
        RemoveNthNodeFromList sobj = new RemoveNthNodeFromList();

        sobj.Insert(1);
        sobj.Insert(2);
        sobj.Insert(3);
        sobj.Insert(4);
        sobj.Insert(5);

        sobj.Display();

        sobj.DeleteAtPos(1);
        sobj.Display();

        sc.close();
    }
}