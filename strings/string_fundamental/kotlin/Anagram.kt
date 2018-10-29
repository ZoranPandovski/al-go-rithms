fun String.isAnagram(input : String) : Boolean {
    val charArray1 = this.toUpperCase().toCharArray()
    val charArray2 = input.toUpperCase().toCharArray()

    charArray1.sort()
    charArray2.sort()

    return charArray1.contentEquals(charArray2)
}

fun main(args: Array<String>) {
    println("test".isAnagram("test"))
    println("test".isAnagram("tets"))
    println("test".isAnagram("teiu"))
}