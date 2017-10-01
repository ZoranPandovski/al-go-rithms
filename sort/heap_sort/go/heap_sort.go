package heapsort

// HeapSort sorts an integer slice by using the heap sort algorithm.
// The following implementation is a go port from the pseudocode, that can be
// found on https://en.wikipedia.org/wiki/Heapsort#Pseudocode.
func HeapSort(slice []int) {
	heapify(slice)
	end := len(slice) - 1
	for end > 0 {
		slice[end], slice[0] = slice[0], slice[end]
		end--
		siftDown(slice, 0, end)
	}
}

func heapify(slice []int) {
	start := (len(slice) - 2) / 2
	for start >= 0 {
		siftDown(slice, start, len(slice)-1)
		start--
	}
}

func siftDown(slice []int, start int, end int) {
	root := start
	for root*2+1 <= end {
		child := root*2 + 1
		swap := root
		if slice[swap] < slice[child] {
			swap = child
		}
		if child+1 <= end && slice[swap] < slice[child+1] {
			swap = child + 1
		}
		if swap == root {
			return
		}
		slice[root], slice[swap] = slice[swap], slice[root]
		root = swap
	}
}
