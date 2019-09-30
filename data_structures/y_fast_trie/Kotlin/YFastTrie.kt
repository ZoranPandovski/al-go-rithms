/**
 * Y-fast trie is a data structure for storing integers from a bounded domain
 * It supports exact and predecessor or successor queries in time O(log log M), using O(n) space, 
 * where n is the number of stored values and M is the maximum value in the domain.
 * More info about the structure and complexity here: https://en.wikipedia.org/wiki/Y-fast_trie
 *
 * The prerequisites are the XFastTrie (al-go-rithms/data_structures/x_fast_trie/Kotlin/XFastTrie.kt) and a Balanced BST.
 * In this implementation a Treap is used (al-go-rithms/data_structures/treap/Kotlin/persistent_treap.kt)
 */
 

class XFastMap<T>(domain: Long) {

    private val base = XFastTrie(domain)
    private val valueTable: MutableMap<Long, T> = HashMap()

    fun add(entry: Pair<Long, T>) {
        base.add(entry.first)
        valueTable.put(entry.first, entry.second)
    }

    fun emplace(key: Long, value: T) {
        valueTable[key] = value
    }

    fun successor(key: Long): Pair<Long?, T?> {
        val nextKey = base.successor(key)
        return Pair(nextKey, valueTable.get(nextKey))
    }

    fun predecessor(key: Long): Pair<Long?, T?> {
        val nextKey = base.predecessor(key)
        return Pair(nextKey, valueTable.get(nextKey))
    }

    fun get(key: Long) = valueTable.get(key)

    fun delete(key: Long) {
        base.delete(key)
        valueTable.remove(key)
    }

}

class YFastTrie(domain: Long) {

    class Node(val representative: Long, val bst: PersistentTreap<Long> = PersistentTreap())

    private val xFast: XFastMap<Node> = XFastMap(domain)
    private val logM: Int = java.lang.Long.numberOfLeadingZeros(0) - java.lang.Long.numberOfLeadingZeros(domain) + 1


    fun find(key: Long): Boolean {
        val succRepr = xFast.successor(key).second
        val prevRepr = xFast.predecessor(key+1).second
        return (succRepr?.bst?.search(key) ?: false) or (prevRepr?.bst?.search(key) ?: false)

    }

    fun successor(key: Long): Long? {
        var succRepr = xFast.successor(key).second
        if (succRepr != null && succRepr.bst.successor(key) == null)
            succRepr = xFast.successor(succRepr.representative).second
        val prevRepr = xFast.predecessor(key+1).second
        val succ1 = succRepr?.bst?.successor(key)
        val succ2 = prevRepr?.bst?.successor(key)
        if (succ1 == null) return succ2
        if (succ2 == null) return succ1
        return java.lang.Long.min(succ1, succ2)
    }

    fun predecessor(key: Long): Long? {
        val succRepr = xFast.successor(key).second
        var prevRepr = xFast.predecessor(key+1).second
        if (prevRepr != null && prevRepr.bst.predecessor(key) == null)
            prevRepr = xFast.predecessor(prevRepr.representative).second
        val succ1 = succRepr?.bst?.predecessor(key)
        val succ2 = prevRepr?.bst?.predecessor(key)
        if (succ1 == null) return succ2
        if (succ2 == null) return succ1
        return java.lang.Long.max(succ1, succ2)
    }

    fun add(key: Long) {
        val succRepr = xFast.successor(key).second
        val prevRepr = xFast.predecessor(key+1).second
        val succ1 = succRepr?.bst?.successor(key)
        val succ2 = prevRepr?.bst?.successor(key)
        val reprNode = when {
            succ1 == null -> prevRepr
            succ2 == null -> succRepr
            succ1 < succ2 -> succRepr
            else -> prevRepr
        }
        val tree = reprNode?.bst

        if (tree == null) {
            val addedTree = PersistentTreap<Long>() + key
            xFast.add(Pair(key, Node(key, addedTree)))
            return
        }
        val newTree = tree + key

        if (newTree.size > 2*logM) {
            val pivot = when {
                newTree.root!!.rightChild == null -> newTree.root.value - 1
                newTree.root.leftChild == null -> newTree.root.value + 1
                else -> newTree.root.value
            }
            val (leftTree, rightTree) = newTree.split(pivot)
            xFast.delete(reprNode.representative)
            val leftRepr = leftTree.root!!.value
            val rightRepr = rightTree.root!!.value
            xFast.add(Pair(leftRepr, Node(leftRepr, leftTree)))
            xFast.add(Pair(rightRepr, Node(rightRepr, rightTree)))
        }
        else
            xFast.emplace(reprNode.representative, Node(reprNode.representative, newTree))
    }

    fun delete(key: Long): Boolean {
        val succRepr = xFast.successor(key).second
        val prevRepr = xFast.predecessor(key + 1).second
        val myRepr = when {
            succRepr?.bst?.search(key) == true -> succRepr
            prevRepr?.bst?.search(key) == true -> prevRepr
            else -> return false
        }
        val newTree = myRepr.bst - key
        if (newTree.size >= logM / 4)
            xFast.emplace(myRepr.representative, Node(myRepr.representative, newTree))
        else {
            val toJoin = xFast.successor(myRepr.representative).second ?: xFast.predecessor(myRepr.representative).second
            if (toJoin == null) {
                xFast.emplace(myRepr.representative, Node(myRepr.representative, newTree))
                return true
            }
            xFast.delete(myRepr.representative)
            xFast.delete(toJoin.representative)

            val newR = myRepr.representative
            xFast.add(Pair(newR, Node(newR, newTree.join(toJoin.bst, newR))))
        }
        return true
    }

}

fun<T> List<T>.firstOrNullBinary(predicate: (T) -> Boolean): T? {
    var step = 1
    var pos = this.size
    while (step < this.size) step *= 2
    while (step > 0) {
        if (pos - step >= 0 && predicate(this[pos-step]))
            pos -= step
        step /= 2
    }
    if (pos == this.size) return null
    return this[pos]
}

fun checkContains(trie: YFastTrie, values: List<Long>, MAX_VALUE: Long) {
    val sortedValues = values.sorted()
    val reverseSortedValues = sortedValues.reversed()
    for (i in 0..MAX_VALUE) {
        val myNext = sortedValues.firstOrNullBinary({it > i})
        val actualNext = trie.successor(i)
        val myPrev = reverseSortedValues.firstOrNullBinary({it < i})
        val actualPrev = trie.predecessor(i)

        if (myNext != actualNext)
            println("error")
        if (myPrev != actualPrev)
            println("error")
    }
    val myContent = (0..MAX_VALUE).filter { trie.find(it) }.sorted().toLongArray()
    if (!(myContent contentEquals values.sorted().toLongArray()))
        println("error")
}


fun main(args: Array<String>) {
    val MAX_VALUE = 1000005L
    val TO_ADD = 200000
    val TO_DELETE = 50000
    val trie = YFastTrie(MAX_VALUE)

    val values = (0..MAX_VALUE).shuffled().subList(0, TO_ADD)
    values.forEach { trie.add(it) }

    println("Check inserts")
    checkContains(trie, values, MAX_VALUE)

    val toDel = values.shuffled().subList(0, TO_DELETE).toSet()
    val rest = values.filter { !toDel.contains(it) }

    toDel.forEach { trie.delete(it) }

    println("Check after delete")
    checkContains(trie, rest, MAX_VALUE)
}
