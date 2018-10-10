fun <T:Comparable<T>>selectionsort(items:MutableList<T>):MutableList<T>{
    if (items.isEmpty()){
        return items
    }
    for (idx in 0..items.count()){
        val array = items.subList(0,items.count()-idx)
        val minItem = array.min()
        val indexOfMinItem = array.indexOf(minItem)

        if (minItem != null) {
            items.removeAt(indexOfMinItem)
            items.add(minItem)
        }
    }
    return items
}


fun main(args: Array<String>) {
    println("Selection Sort")
    val names = mutableListOf("John", "Tim", "Zack", "Daniel", "Adam")
    println(names)
    var ordered = insertionsort(names)
    println(ordered)
}