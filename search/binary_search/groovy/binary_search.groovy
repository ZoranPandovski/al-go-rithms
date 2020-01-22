def binSearchI = { aList, target ->
    def listCpy = aList
    def offset = 0
    while (!a.empty) {
        def listCpySize = listCpy.size()
        def middle = listCpySize.intdiv(2)
        if(listCpy[middle] > target) {
            listCpy = listCpy[0..<middle]
        } else if (listCpy[middle] < target) {
            listCpy = listCpy[(m + 1)..<listCpySize]
            offset += middle + 1
        } else {
            return [index: offset + middle]
        }
    }
    return ["insertion point": offset]
}
