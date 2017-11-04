object BubbleSort {
    def sort(list: Array[Int]): Array[Int] = {
        for (i <- 0 until list.length - 1; j <- 0 until list.length - 1 - i){
            if (list(j) > list(j + 1)){
                var temp = list(j)
                list(j) = list(j + 1)
                list(j + 1) = temp
            }
        }
        list
    }
}