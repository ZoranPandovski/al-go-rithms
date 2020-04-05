func Swap(_ swapArray: inout [Int], _ firstIndex: Int, _ secondIndex: Int) {
    let temp = swapArray[firstIndex]
    swapArray[firstIndex] = swapArray[secondIndex]
    swapArray[secondElLoc] = temp
}

func InsertionSort(_ arr: [Int]) {
    let size = arr.count
    for index in stride(from: 1, to: size, by: 1) {
        var check = index - 1
        while check >= 0 && arr[check] > arr[check + 1] {
            Swap(arr, check, check + 1)
            check -= 1
        }
    }
}

print("Test One:")
print("Input: \([1, 2, 3, 4])")
print("Output: \(InsertionSort([1, 2, 3, 4]))")
print("Test Two:")
print("Input: \([4, 3, 2, 1])")
print("Output: \(InsertionSort([4, 3, 2, 1]))")
print("Test Three:")
print("Input: \([4, 2, 3, 1])")
print("Output: \(InsertionSort([4, 2, 3, 1]))")
