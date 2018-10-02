package radix

import (
	"reflect"
	"unsafe"
)

// Sort sorts a slice of strings in increasing byte-wise lexicographic order.
//
// The function is equivalent to sort.Strings in the standard library.
func Sort(a []string) {
	n := len(a)
	if n < 2 {
		return
	}
	// Put elements into a linked list.
	mem := make([]list, n)
	for i, s := range a {
		mem[i].str = s
		if i < n-1 {
			mem[i].next = &mem[i+1]
		}
	}
	res := msdRadixSort(&mem[0], n)
	for i := range a {
		a[i] = res.str
		res = res.next
	}
}

// SortSlice sorts a slice according to the strings returned by str.
//
// The function panics if the provided interface is not a slice.
func SortSlice(slice interface{}, str func(i int) string) {
	if slice == nil {
		return
	}
	n := reflect.ValueOf(slice).Len()
	if n < 2 {
		return
	}
	// Put elements into a linked list.
	mem := make([]list, n)
	for i := 0; i < n; i++ {
		mem[i].str = str(i)
		if i < n-1 {
			mem[i].next = &mem[i+1]
		}
	}
	res := msdRadixSort(&mem[0], n)
	// Create a permutation that will sort the slice.
	perm := make([]int, n)
	const size = unsafe.Sizeof(list{})
	base := uintptr(unsafe.Pointer(&mem[0]))
	for i := 0; i < n; i++ {
		perm[(uintptr(unsafe.Pointer(res))-base)/size] = i
		res = res.next
	}
	// Apply permutation by swapping.
	swap := reflect.Swapper(slice)
	for i := 0; i < n; i++ {
		for j := perm[i]; j != i; perm[j], j = j, perm[j] {
			swap(i, j)
		}
	}
}

const insertBreak = 16

type list struct {
	str  string
	next *list
}

type bucket struct {
	head, tail *list
	size       int // size of list, 0 if already sorted
}

// Type frame represents a stack frame.
type frame struct {
	head, tail *list
	size       int // size of list, 0 if already sorted
	pos        int // current byte position in string
}

func msdRadixSort(a *list, n int) *list {
	var res *list
	stack := []frame{{head: a, size: n}}
	for len(stack) > 0 {
		top := len(stack) - 1
		frame := stack[top]
		stack = stack[:top]
		if frame.size == 0 { // already sorted
			frame.tail.next = res
			res = frame.head
			continue
		}
		stack = intoBuckets(stack, frame.head, frame.pos)
	}
	return res
}

// intoBuckets traverses a list and puts the elements into buckets
// according to the byte in position p.
func intoBuckets(stack []frame, a *list, p int) []frame {
	var b0 bucket             // 0 bytes
	b1 := make([]bucket, 256) // 1 byte
	min, max := 255, 0        // Keep track of the min and max byte.

	// Move elements in blocks consisting of strings that have
	// a common byte in position p.
	t := a
	prevCh := -1
	if len(t.str) > p {
		prevCh = int(t.str[p])
	}
	size := 1
	for tn := t.next; tn != nil; t, tn = tn, tn.next {
		ch := -1
		if len(tn.str) > p {
			ch = int(tn.str[p])
		}
		size++
		if ch == prevCh {
			continue
		}
		if prevCh == -1 {
			intoBucket0(&b0, a, t)
		} else {
			intoBucket1(&b1[prevCh], a, t, size-1, prevCh, &min, &max)
		}
		a = tn
		prevCh = ch
		size = 1
	}
	if prevCh == -1 {
		intoBucket0(&b0, a, t)
	} else {
		intoBucket1(&b1[prevCh], a, t, size, prevCh, &min, &max)
	}

	if b0.head != nil {
		stack = ontoStack(stack, &b0, p)
	}
	for ch, n := min, max; ch <= n; ch++ {
		if b1[ch].head != nil {
			stack = ontoStack(stack, &b1[ch], p+1)
		}
	}
	return stack
}

// intoBucket0 puts a list of elements into a bucket.
func intoBucket0(b *bucket, head, tail *list) {
	if b.head != nil {
		b.tail.next = head
		b.tail = tail
		return
	}
	b.head = head
	b.tail = tail
}

// intoBucket1 puts a list of elements into a bucket.
// The min and max bytes seen so far  are updated when the bucket
// is updated for the first time.
func intoBucket1(b *bucket, head, tail *list, size int,
	ch int, min, max *int) {
	if b.head != nil {
		b.tail.next = head
		b.tail = tail
		b.size += size
		return
	}
	b.head = head
	b.tail = tail
	b.size = size
	if ch < *min {
		*min = ch
	}
	if ch > *max {
		*max = ch
	}
}

// ontoStack puts the list in a bucket onto the stack.
func ontoStack(stack []frame, b *bucket, pos int) []frame {
	b.tail.next = nil
	if b.size <= insertBreak {
		if b.size > 1 {
			b.head, b.tail = insertSort(b.head, pos)
		}
		b.size = 0 // Mark as sorted.
	}
	// If both the the list on top of the stack and the new list are sorted,
	// the new list is appended and no stack record is created.
	if top := len(stack) - 1; top >= 0 && stack[top].size == 0 && b.size == 0 {
		stack[top].tail.next = b.head
		stack[top].tail = b.tail
		return stack
	}
	stack = append(stack, frame{
		head: b.head,
		tail: b.tail,
		size: b.size,
		pos:  pos,
	})
	return stack
}

// insertSort sorts a list comparing strings starting at byte position p.
// It returns the head and the tail of the sorted list.
func insertSort(a *list, p int) (head, tail *list) {
	head, tail = a, a
	for r := head.next; r != nil; r = tail.next {
		s := r.str[p:]
		switch {
		case tail.str[p:] <= s: // Add to tail.
			tail = r
		case head.str[p:] >= s: // Add to head.
			tail.next = r.next
			r.next = head
			head = r
		default: // Insert into middle.
			t := head
			for t.next.str[p:] <= s {
				t = t.next
			}
			tail.next = r.next
			r.next = t.next
			t.next = r
		}
	}
	return
}
