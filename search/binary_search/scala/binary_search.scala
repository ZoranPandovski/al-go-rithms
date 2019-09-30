/**
* Recursive binary search algorithm 
* @param list the integer array which is being searched (sorted list)
* @param l lower value for partition
* @param r upper value for partition
* @param num number which is being searched for
* @return the index of the element that matches the search term, returns -1 if not found
*/
def binary_search(list: Array[Int], l: Int, r: Int, num:Int): Int = {
  if (l <= r) {
    val mid = (l+r)/2
    if (list(mid) == num) return mid
    else if (list(mid) <  num ) return binary_search(list, mid + 1, r, num) 
    else
      return binary_search(list, l, mid - 1, num)
  }
  return -1
}

def test(){
  val l = Array(1, 3, 4, 5, 6, 7)
  assert(binary_search(l, 0, l.length - 1, 4) == 2)
  assert(binary_search(l, 0, l.length - 1, 8) == -1)
  assert(binary_search(l, 0, l.length - 1, 2) == -1)
  assert(binary_search(l, 0, l.length - 1, 6) == 4) 
}
