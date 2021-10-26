object InsertionSort {

  def insertionSort(arr: Array[Int]): Array[Int] = {
    for (i <- 1 to arr.length - 1) {
      val currentValue = arr(i)
      var j = i - 1
      while (j >= 0 && currentValue < arr(j)) {
        arr(j + 1) = arr(j)
        arr(j) = currentValue
        j = j - 1
      }
    }
    arr
  }

  def main(args: Array[String]): Unit = {
    val arr = Array(3, 1, 4, 5, 9, 2, 6, 8, 7, 10)
    val sortedArray = insertionSort(arr)
    println(sortedArray.mkString(", "))
  }
}
