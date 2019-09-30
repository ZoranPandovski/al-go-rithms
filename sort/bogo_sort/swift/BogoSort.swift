func isSorted(list: [Int]) -> Bool {
    for i in 0..<list.count - 1 {
        if list[i] > list[i + 1] {
            return false
        }
    }
    return true
}

func shuffle(list: [Int]) -> [Int] {
    var newList: [Int] = []
    for value in list {
        newList.insert(value, at: Int.random(in: 0 ... newList.count))
    }
    return newList
}

func bogoSort(list: [Int]) -> [Int] {
    if isSorted(list: list) {
        return list
    }
    return bogoSort(list: shuffle(list: list))
}

print(bogoSort(list: [1,3,2,4]))
