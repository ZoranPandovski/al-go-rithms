//Implementation of min heap in java

public class Minheap 
{
    private int heap[];
    private int size;
    private int maxsize;

    private static int root = 1;

    //constructor to initialize size
    Minheap(int maxsize)
    {
        this.maxsize = maxsize;
        this.size = 0;
        heap = new int[maxsize + 1];
        heap[0] = Integer.MIN_VALUE;
    }

    //return parent of given node
    int parent(int pos)
    {
        return pos/2;
    }

    //return leftchild of given node
    int leftchild(int pos)
    {
        return 2*pos; 
    }

    //return rightchild of given node
    int rightchild(int pos)
    {
        return (2*pos+1); 
    }


    boolean leafnode(int pos)
    {
        if(pos > (size/2) && pos <= size)
            return true;
        else
            return false;
    }

    //function to swap 2 nodes
    void swap(int pos1, int pos2)
    {
        int tmp = heap[pos1];
        heap[pos1] = heap[pos2];
        heap[pos2] = tmp;
    }

    // to heapify at given node to main the heap constraints
    void minheapify(int pos)
    {
        if(!leafnode(pos))
        {
            if(heap[pos] > heap[leftchild(pos)])
            {
                swap(pos,leftchild(pos));
                minheapify(leftchild(pos));
            }

            if(heap[pos] > heap[rightchild(pos)])
            {
                swap(pos,rightchild(pos));
                minheapify(rightchild(pos));
            }
        }
    }

    // function to insert nodes to the heap
    void insert(int value)
    {
        if(size >= maxsize)
            return;

        heap[++size] = value;

        int current = size;
        while(heap[current] < heap[parent(current)])
        {
            swap(current,parent(current));
            current = parent(current);
        }
    }

    //to build the initial heap
    void minheap()
    {
        for(int pos = 1;pos <= (size/2); pos++)
            minheapify(pos);
    }

    // To extract root node that contains the minimum element
    int remove()
    {
        int popped = heap[root];
        heap[root] = heap[size--];
        minheapify(root);
        return popped;
    }

    //to print the heap
    public void print() 
    { 
        for (int i = 1; i <= size / 2; i++) { 
            System.out.print(" PARENT : " + heap[i] 
                             + " LEFT CHILD : " + heap[2 * i] 
                             + " RIGHT CHILD :" + heap[2 * i + 1]); 
            System.out.println(); 
        } 
    } 

    //driver program
    public static void main(String[] args) {
        System.out.println("The Min Heap is "); 
        Minheap minHeap = new Minheap(15); 
        minHeap.insert(5); 
        minHeap.insert(3); 
        minHeap.insert(17); 
        minHeap.insert(10); 
        minHeap.insert(84); 
        minHeap.insert(19); 
        minHeap.insert(6); 
        minHeap.insert(22); 
        minHeap.insert(9); 
        minHeap.minheap(); 
  
        minHeap.print(); 
        System.out.println("The min val is " + minHeap.remove());
    }
}
