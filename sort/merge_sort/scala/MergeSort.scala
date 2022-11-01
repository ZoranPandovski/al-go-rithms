object MergeSort {

  def merge(leftArr: Array[Int], rightArr: Array[Int]) = {
    var leftIndex = 0
    var rightIndex = 0

    var sortedArr = Array.empty[Int]

    while (leftIndex < leftArr.length && rightIndex < rightArr.length) {
      if (leftArr(leftIndex) < rightArr(rightIndex)) {
        sortedArr = sortedArr.appended(leftArr(leftIndex))
        leftIndex += 1
      } else {
        sortedArr = sortedArr.appended(rightArr(rightIndex))
        rightIndex += 1
      }
    }

    val restLeft = leftArr.slice(leftIndex, leftArr.length)
    val restRight = rightArr.slice(rightIndex, rightArr.length)

    sortedArr ++ restLeft ++ restRight
  }

  def mergeSort(arr: Array[Int]): Array[Int] = {
      if (arr.length <= 1) return arr

      val mid = arr.length / 2
      var (left, right) = arr.splitAt(mid)

      left = mergeSort(left)
      right = mergeSort(right)

      merge(left, right)
  }


  def main(args: Array[String]): Unit = {
    val arr = Array(11, 3, 1, 13, 4, 5, 12, 9, 2, 6, 8, 7, 10)
    val sortedArray = mergeSort(arr)
    println(sortedArray.mkString(", "))
  }

}
