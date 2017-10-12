public class IntArrayStack
{
    int[] theArrayStack;
    int nextAvailableSpot;//Is also the amount of items on the stack
    
    public IntArrayStack()
    {
    	this(20);
    }
    public IntArrayStack(int size)
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
