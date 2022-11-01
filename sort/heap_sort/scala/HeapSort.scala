object HeapSort {

  def swap(arr: Array[Int], a: Int, b: Int) = {
    val aux = arr(a)
    arr(a) = arr(b)
    arr(b) = aux
  }

  def heapify(arr: Array[Int], n: Int, i: Int): Unit = {
    var largest = i
    val left = 2 * i + 1
    val right = 2 * i + 2

    if (left < n && arr(left) > arr(largest)) largest = left
    if (right < n && arr(right) > arr(largest)) largest = right

    if (largest != i) {
      swap(arr, i, largest)
      heapify(arr, n, largest)
    }
  }

  def heapSort(arr: Array[Int]) = {
    val sortedArr = arr.clone()
    val n = sortedArr.length

    for (i <- n / 2 - 1 to 0 by -1) {
      heapify(sortedArr, n, i)
    }

    for (i <- n - 1 to 0 by -1) {
      swap(sortedArr, 0, i)
      heapify(sortedArr, i, 0)
    }

    sortedArr
  }


  def main(args: Array[String]): Unit = {
    val arr = Array(3, 1, 4, 5, 9, 2, 6, 8, 7, 10)
    val sortedArray = heapSort(arr)
    println(sortedArray.mkString(", "))
  }
}
