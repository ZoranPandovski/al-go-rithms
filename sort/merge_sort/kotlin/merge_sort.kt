fun mergeSortIA(array: IntArray) : IntArray {
    val arrayCopy = array.copyOf()
    val arrayCopy2 = array.copyOf()

    sortSectionIA(arrayCopy, arrayCopy2, 0, arrayCopy.size)

    return arrayCopy2
}

/**
 * Sorts the specified section of the array.
 *
 * @param workA Should contain identical values as workB in the specified range.
 *              The final values in the specified range are destroyed (actually they are made
 *              of two adjacent sorted ranged).
 * @param workB Should contain identical values as workA in the specified range.
 *              The final values in the specified range are the sorted values in that range.
 */
internal inline fun mergeHalvesIA(workA: IntArray,
                                  workB: IntArray,
                                  start: Int,
                                  mid: Int,
                                  exclusiveEnd: Int) {
    var p1 = start
    var p2 = mid
    for (i in start until exclusiveEnd) {
        if (p1 < mid && (p2 == exclusiveEnd || workA[p1] <= workA[p2])) {
            workB[i] = workA[p1]
            p1++
        } else {
            workB[i] = workA[p2]
             p2++
        }
    }
}

internal fun sortSectionIA(input: IntArray,
                           output: IntArray,
                           start: Int,
                           exclusiveEnd: Int) : Unit {

    if (exclusiveEnd - start <= 1)
        return
    val mid = (start + exclusiveEnd) / 2
    sortSectionIA(output, input, start, mid)
    sortSectionIA(output, input, mid, exclusiveEnd)
    mergeHalvesIA(input, output, start, mid, exclusiveEnd)
}
