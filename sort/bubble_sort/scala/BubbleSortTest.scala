import BubbleSort._

object BubbleSortTest {
    def main(args: Array[String]) {
        val list = Array(5,6,99,1,14,46,19,2)
        val result = BubbleSort.sort(list)

        for (i <- result){
            print(i + " ")
        }

    }
}