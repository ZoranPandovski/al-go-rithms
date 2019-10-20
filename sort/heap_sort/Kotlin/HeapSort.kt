/* 
Heapsort is an in-place sorting algorithm with worst case and average complexity of O(n*logn).
The basic idea is to turn the array into a binary heap structure, which has the property that it allows efficient retrieval and removal of the maximal element.
We repeatedly "remove" the maximal element from the heap, thus building the sorted list from back to front.
Heapsort requires random access, so can only be used on an array-like data structure.
*/

fun heapSort(a: IntArray) {
    heapify(a)
    var end = a.size - 1
    while (end > 0) {
        val temp = a[end]
        a[end] = a[0]
        a[0] = temp
        end--
        siftDown(a, 0, end)
    }
}
 
fun heapify(a: IntArray) {
    var start = (a.size - 2) / 2
    while (start >= 0) {
        siftDown(a, start, a.size - 1)
        start--
    }
}
 
fun siftDown(a: IntArray, start: Int, end: Int) {
    var root = start
    while (root * 2 + 1 <= end) {
        var child = root * 2 + 1
        if (child + 1 <= end && a[child] < a[child + 1]) child++
        if (a[root] < a[child]) {
            val temp = a[root]
            a[root] = a[child]
            a[child] = temp
            root = child
        }
        else return
    }
}
 
fun main(args: Array<String>) {
    val aa = arrayOf(
        intArrayOf(100, 2, 56, 200, -52, 3, 99, 33, 177, -199),
        intArrayOf(4, 65, 2, -31, 0, 99, 2, 83, 782, 1),
        intArrayOf(12, 11, 15, 10, 9, 1, 2, 3, 13, 14, 4, 5, 6, 7, 8)
    )
    for (a in aa) {
        heapSort(a)
        println(a.joinToString(", "))
    }
}