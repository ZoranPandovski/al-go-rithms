func Swap(_ swapArray: inout [Int], _ firstIndex: Int, secondIndex: Int) {
  let temp = swapArray[firstIndex]
  swapArray[firstIndex] = swapArray[secondIndex]
  swapArray[secondIndex] = temp
}

func BubbleSort(_ arr: inout [Int]) {
  var didSwap = false
  var endIndex = arr.count - 1
  repeat {
    didSwap = false
    for index in stride(from: 0, to: endIndex, by: 1) {
      if arr[index] > arr[index + 1] {
        Swap(&arr, index, index + 1)
        didSwap = true
      }
    }
    endIndex -= 1
  } while didSwap
}

print(BubbleSort([1, 2, 3, 4]))
print(BubbleSort([4, 3, 2, 1]))
print(BubbleSort([1, 3, 4, 2]))
