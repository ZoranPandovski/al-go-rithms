public class Heap {
    public int index;
    int[] list;
    public int length; //Number of elements in the array
    public int size; //Number of elements stored in the array that are from the heap

    public Heap(int[] list){
        this.list = list;
    }
    public Heap(int index) {
        this.index = index;
    }
    public int parent(int index){
        return index >> 1;
    }
    public int leftChild(int index){
        return index << 1;
    }
    public int rightChild(int index){
        return (index << 1) + 1;
    }

    private void swap(int node1, int node2)
    {

        int temp;
        temp = list[node1];

        list[node1] = list[node2];
        list[node2] = temp;
    }

    public void minHeapify(int index){
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest;

        if(left <= size && list[left] < list[index]){
            smallest = left;
        }
        else {
            smallest = index;
        }

        if(right <= size && list[right] < list[index]){
            smallest = right;
        }

        if(smallest != index){
            swap(index, smallest);
            minHeapify(smallest);
        }

    }

    public void printHeap(){
        for(int i = 0; i < size; i++){
            System.out.print(this.list[i]);
            System.out.print(" ");
        }
        System.out.println();
    }
  
    public void insert(int key){
        if(size < length) {
            size++;
            list[size - 1] = key;
        }

        minHeapify(key);
    }
