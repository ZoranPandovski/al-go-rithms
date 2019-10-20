/**
 *  Van Emde Boas tree implementation
 *  Supports operations of an ordered associative array:
 *      Insert: insert a key/value pair with an m-bit key
 *      Delete: remove the key/value pair with a given key <- Not yet implemented
 *      Lookup: find the value associated with a given key
 *      FindNext: find the key/value pair with the smallest key which is greater than a given k
 *      FindPrevious: find the key/value pair with the largest key which is smaller than a given k
 *  Average complexity for insert and find is O(log log M) where M is the maximum number of elements that can be stored in the tree
 *  Space complexity O(M)
 */

class VEB<VAL_TYPE> (universeDim: Int) {

    private val universeBits = 32-java.lang.Integer.numberOfLeadingZeros(universeDim)
    private val halfBits = universeBits shr 1
    private val lowMask = (1 shl halfBits) - 1
    private val highMask = (1 shl universeBits) - 1 - lowMask
    private fun localize(upBits: Int) = upBits shr halfBits
    private val children = arrayOfNulls<VEB<VAL_TYPE>>(1 shl (universeBits - halfBits))
    private var summary: VEB<Boolean>? = null

    private var minKey: Int? = null
    private var maxKey: Int? = null

    private var minValue: VAL_TYPE? = null
    private var maxValue: VAL_TYPE? = null

    fun getMin() = if (minKey == null) null else Pair(minKey!!, minValue!!)
    fun getMax() = if (maxKey == null) null else Pair(maxKey!!, maxValue!!)

    fun lookup(key: Int) : VAL_TYPE? {
        val subtree = localize(key and highMask)
        val child = key and lowMask
        return if (key == minKey) minValue else children[subtree]?.lookup(child)
    }

    fun findNext(key: Int) : Pair<Int, VAL_TYPE>? {
        if (maxKey == null || key >= maxKey!!)
            return null
        if (key < minKey!!)
            return Pair(minKey!!, minValue!!)
        val subtree = localize(key and highMask)
        val child = key and lowMask
        val maxValInSubtree = children[subtree]?.getMax()?.first
        val (baseIndex, solution) =  if (maxValInSubtree == null || child >= maxValInSubtree) {
            val baseIndex = summary!!.findNext(subtree)!!.first
            val solution = children[baseIndex]!!.getMin()!!
            Pair(baseIndex, solution)
        } else {
            val solution = children[subtree]!!.findNext(child)!!
            Pair(subtree, solution)
        }
        return Pair(baseIndex*(lowMask + 1) + solution.first, solution.second)
    }

    fun findPrevious(key: Int) : Pair<Int, VAL_TYPE>? {
        if (maxKey == null || key <= minKey!!)
            return null
        if (key > maxKey!!)
            return Pair(maxKey!!, maxValue!!)
        val subtree = localize(key and highMask)
        val child = key and lowMask
        val minValInSubtree = children[subtree]?.getMin()?.first
        val (baseIndex, solution) =  if (minValInSubtree == null || child <= minValInSubtree) {
            val base = summary!!.findPrevious(subtree)
            if (base == null)
                Pair(0, Pair(minKey!!, minValue!!))
            else {
                val solution = children[base.first]!!.getMax()!!
                Pair(base.first, solution)
            }
        } else {
            val solution = children[subtree]!!.findPrevious(child)!!
            Pair(subtree, solution)
        }
        return Pair(baseIndex*(lowMask + 1) + solution.first, solution.second)
    }

    private fun initTree(key: Int, value: VAL_TYPE) {
        minKey = key
        maxKey = key
        minValue = value
        maxValue = value
        summary = VEB(children.size)
    }

    fun insert(key: Int, value: VAL_TYPE) {
        if (minKey == null)
            return initTree(key, value)
        val (propKey, propVal) = when {
            key < minKey!! -> Pair(minKey!!, minValue!!).also { minKey = key; minValue = value}
            key > maxKey!! -> Pair(key, value).also { maxKey = key; maxValue = value}
            else -> Pair(key, value)
        }
        val subtree = localize(propKey and highMask)
        val child = propKey and lowMask

        if (children[subtree] == null) {
            children[subtree] = VEB(lowMask)
            summary!!.insert(subtree, true)
        }
        children[subtree]!!.insert(child, propVal)
    }
}


/* Testing */
fun main(args: Array<String>) {
    val universe = 10000
    val toInsert = arrayListOf(15, 18, 25, 28, 49, 154, 2890, 7345, 8723)
    val shuffled = toInsert.shuffled()


    val veb = VEB<String>(universe)
    shuffled.forEach { veb.insert(it, it.toString()) }

    for (i in 0 until universe) {
        val selected = veb.findNext(i)
        if (selected?.first != toInsert.firstOrNull { it > i })
            println("Error at $i")
        if (veb.findPrevious(i)?.first != toInsert.lastOrNull { it < i })
            println("Error at $i")
        if (selected?.first?.toString() != selected?.second)
            println("Error at $i")
        if (veb.lookup(i) != toInsert.firstOrNull { it == i } ?. toString())
            println("Error at $i")
    }

}