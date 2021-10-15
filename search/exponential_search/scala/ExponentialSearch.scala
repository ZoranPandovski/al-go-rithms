object ExponentialSearch {


  def binarySearch(arr: Array[Int], _low: Int, _high: Int, x: Int): Int = {
    var low = _low
    var high = _high

    while (low <= high) {
      val mid = (high + low)/2

      if(arr(mid) == x) {
        return mid
      } else if (arr(mid) < x) {
        low = mid + 1
      } else {
        high = mid - 1
      }
    }

    -1
  }

  def exponentialSearch(arr: Array[Int], x: Int): Int = {
    val n: Int = arr.length

    if(arr(0) == x) {
      return 0
    }

    var i = 1
    while (i < n && arr(i) <= x) i = i * 2

    binarySearch(arr, i/2, i.min(n - 1), x)
  }

  def main(args: Array[String]): Unit = {
      val arr = Array.range(5, 500)
      val index = exponentialSearch(arr, 105)
      println(s"Index: $index")
  }
}
