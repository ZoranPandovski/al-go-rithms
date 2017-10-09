public class Heap_sort {
    private int n;
    void heapSort(int h[])
    {
//	heapsort algorithm
        heapify(h);        
        for (int i = n; i > 0; i--)
        {
            int aux = h[0];
            h[0] = h[i];
            h[i] = aux;
            n = n-1;
            maxheap(h, 0);
        }
    }     
    
    void heapify(int h[])
    {
//	Makes the heap
        n = h.length-1;
        for (int i = n/2; i >= 0; i--)
            maxheap(h, i);        
    }
       
    void maxheap(int h[], int i)
    { 
//	Swap the largest element in heap
        int left = 2*i ;
        int right = 2*i + 1;
        int max = i;
        if (left <= n && h[left] > h[i])
            max = left;
        if (right <= n && h[right] > h[max])        
            max = right;
        if (max != i)
        {
            int aux = h[max];
            h[max] = h[i];
            h[i] = aux;
            maxheap(h, max);
        }

    }    
	
	public static void main (String args[])
	{
		//Test:
		
		Heap_sort H = new Heap_sort();
		int h[] = {5,2,6,1,9,10,3,4};
		H.heapSort(h);
		for (int i=0;i<h.length;i++)
			System.out.println(h[i]);
		
	}
}
