object QuickSort extends App {
  def sort(list: List[Int]): List[Int] = {
    list match {
      case Nil => Nil
      case oneElementList :: Nil => List(oneElementList)
      case pivot :: tail => {
        val (less, greater) = tail.partition(_ < pivot)
        sort(less) ::: pivot :: sort(greater)
      }
    }
  }

  val originalList = List(10, 7, 8, 9, 1, 5)
  val sortedList = sort(originalList)
  println(s"originalList: ${originalList}")
  println(s"sortedList: ${sortedList}")
}
