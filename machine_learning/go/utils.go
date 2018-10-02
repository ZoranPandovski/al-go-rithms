package main

import (
	"container/heap"
	"io/ioutil"
	"strconv"
	"strings"
)

/*-------------------------------------------------------*/
// Distances

func euclidean(itemA, itemB []float64) (d float64) {
	for i := 0; i < len(itemA); i++ {
		d += (itemA[i] - itemB[i]) * (itemA[i] - itemB[i])
	}

	return
}

/*-------------------------------------------------------*/
// Data

func ReadData(fname string) (items []Item) {
	/* Given a file name, read its contents into a list of Items */
	bytes, _ := ioutil.ReadFile("aima-data/" + fname)
	data := strings.Split(string(bytes), "\n")

	for _, item := range data {
		if !strings.ContainsAny(item, ",") {
			break
		}

		values := strings.Split(item, ",")
		l := len(values)
		f := ConvertStrListToFloat64(values[:l-1])
		c := values[l-1]

		items = append(items, Item{features: f, class: c})
	}

	return
}

/*-------------------------------------------------------*/
// Conversions

func ConvertStrListToFloat64(list []string) (fList []float64) {
	for _, v := range list {
		f, _ := strconv.ParseFloat(v, 64)
		fList = append(fList, f)
	}

	return
}

/*-------------------------------------------------------*/
// Lists

func Occurences(list []string) map[string]int {
	/* Find how many times each element appears in list */
	m := make(map[string]int)
	for _, e := range list {
		if KeyInMap(e, m) {
			m[e] += 1
		} else {
			m[e] = 1
		}
	}

	return m
}

/*-------------------------------------------------------*/
// Map

func FindMaxInMap(m map[string]int) string {
	/* Find key with max value in map m. If there are multiple keys with the
	same max value, return an empty string. */
	max := -1
	key := ""
	for k, v := range m {
		if v > max {
			max = v
			key = k
		} else if v == max {
			key = ""
		}
	}

	return key
}

func KeyInMap(key string, m map[string]int) bool {
	/*Is key in map m?*/
	_, ok := m[key]
	return ok
}

/*-------------------------------------------------------*/
// Heap

type MinHeap []string

func InitMinHeap() *MinHeap {
	/* Each element in heap is in the format "weight-name" */
	h := &MinHeap{}
	heap.Init(h)

	return h
}

func (h *MinHeap) HeapPop() (float64, string) {
	item := heap.Pop(h).(string)

	values := strings.Split(item, "-")
	weight, _ := strconv.ParseFloat(values[0], 64)
	return weight, values[1]
}

func (h *MinHeap) HeapPush(weight float64, item string) {
	toPush := strconv.FormatFloat(float64(weight), 'f', -1, 64) + "-" + item
	heap.Push(h, toPush)
}

func (h *MinHeap) SmallestN(n int) (nItems []string) {
	/* Return n smallest elements */
	for n > 0 {
		_, item := h.HeapPop()
		nItems = append(nItems, item)
		n -= 1
	}

	return
}

func (h MinHeap) Len() int      { return len(h) }
func (h MinHeap) Swap(i, j int) { h[i], h[j] = h[j], h[i] }

func (h MinHeap) Less(i, j int) bool {
	hi, _ := strconv.ParseFloat(strings.Split(h[i], "-")[0], 64)
	hj, _ := strconv.ParseFloat(strings.Split(h[j], "-")[0], 64)
	return hi < hj
}

func (h *MinHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(string))
}

func (h *MinHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
