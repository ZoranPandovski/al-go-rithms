using System;

namespace heapsort
{
    class HeapSort
    {
        static void Main(string[] args)
        {
            HeapSort heapsorter = new HeapSort();
            //Unsorted array
            int[] array = {1,14,10,9,3,6,2,8,5,7,16,4};

            //Create a max heap
            for (int i = array.Length / 2 - 1; i >= 0; i--) {
                heapsorter.heapify(array, i, array.Length); 
            }

            //Sift down the heap
            for (int i = array.Length - 1; i >= 0; i--) 
            {
                heapsorter.swap(array, 0, i);
                heapsorter.heapify(array, 0, i); 
            } 

            //Output result
            Console.Write("Sorted array: ");
            foreach(var item in array) {
                Console.Write(item.ToString() + " ");
            }
            Console.Write("\n");
        }

        //Create max heap from array
        public void heapify(int[] heap, int start, int end) {
            int left = 2 * start + 1;
            int right = 2 * start + 2;

            int largest = start;

            //If the left node is larger than the current largest, it becomes the new largest
            if (left < end && heap[left] > heap[largest]) {
                largest = left;
            }

            //If the right node is larger than the current largest, it becomes the new largest
            if (right < end && heap[right] > heap[largest]) {
                largest = right;
            } 
            
            //If we haven't moved the largest element to the root node, keep going
            if (largest != start) {
                swap(heap, start, largest);
                heapify(heap, largest, end);
            }
        }

        //Swap two array elements
        public void swap(int[] array, int x, int y) {
            int temp = array[x];
            array[x] = array[y];
            array[y] = temp;
        }
    }
}
