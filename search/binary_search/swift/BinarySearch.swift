func binarySearch(find: Int, arr: [Int], start: Int = 0, end: Int?) -> Int? {
    let endValue = end ?? arr.count - 1
    let middle = (endValue - start)/2 + start
    if arr[middle] == find {
        return middle
    } else {
        if endValue == start {
            return nil
        } else {
            if find > arr[middle] {
                return binarySearch(find: find, arr: arr, start: middle + 1, end: endValue)
            } else {
                return binarySearch(find: find, arr: arr, start: start, end: middle - 1)
            }
        }
    }
}
