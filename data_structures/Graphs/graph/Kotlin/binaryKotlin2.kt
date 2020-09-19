// Only Applies To Sorted Data - Efficient Binary Search in Kotlin by Kendall Jackson
internal class BinarySearch {
  // Returns index of x if it is present in arr, otherwise -1
  fun binarySearch(arr:IntArray, l:Int, r:Int, target:Int):Int {
    if (r >= l)
    {
      val mid = l + (r-l) / 2
      // If the element is present at the median (edge case gets priority)
      if (arr[mid] == target)
      return mid
      // If target value smaller than median of a sorted array, then
      // it can only be in left half of the array
      if (arr[mid] > target)
      return binarySearch(arr, l, mid - 1, target)
      // Can only be present on right half
      return binarySearch(arr, mid + 1, r, target)
    }
    // Not found in array, must return -1
    return -1
  }
}
  fun main(args : Array<String>) {
      val obj = BinarySearch()
      // Test Data
      val arr = intArrayOf(2, 3, 4, 9, 40, 97, 945)
      
      // Searching for value: 9
      val test_value = 9
      val result = obj.binarySearch(arr, 0, arr.size-1, test_value)
      // Edge case gets priority again
      if (result == -1)
      println("Element not found.")
      else
      println(("Element found at index: " + result))
    }
