func binarySearch<T: Comparable>(_ arr: [T], key: T) -> Int? {
    var lowerBound = 0
    var upperBound = arr.count
    while lowerBound < upperBound {
        let midIdx = lowerBound + (upperBound - lowerBound) / 2
        if arr[midIdx] == key {
            return midIdx
        } else if arr[midIdx] < key {
            lowerBound = midIdx + 1
        } else {
            upperBound = midIdx
        }
    }
    return nil
}

let numbers = [1, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59]
binarySearch(numbers, key: 37)
