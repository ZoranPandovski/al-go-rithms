extension Heap {

  func sorted() -> [Element] {
    /* 1.You first make a copy of the heap. 
        After heap sort sorts the elements array, it is no longer a valid heap. 
        By working on a copy of the heap, you ensure the heap remains valid. */
        
        var heap = Heap(sort: sort, elements: elements) 

    /* 2. You loop through the array, starting from the last element. */

    for index in heap.elements.indices.reversed() { 

        /* 3. You swap the first element and the last element. 
              This moves the largest unsorted element to its correct spot*/

              heap.elements.swapAt(0, index)

        /* 4. Because the heap is now invalid, you must sift down the new root node. 
              As a result, the next largest element will become the new root.*/

              heap.siftDown(from: 0, upTo: index)
    }
    return heap.elements
  }
}

// Example 

let heap = Heap(sort: >, elements: [6, 12, 2, 26, 8, 18, 21, 9, 5])
print(heap.sorted())


// Output : [2, 5, 6, 8, 9, 12, 18, 21, 26]