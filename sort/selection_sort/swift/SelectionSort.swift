func selectionSort(unsortArr: [Int]) -> [Int] {
    var cloneArr = unsortArr

    for i in 0...cloneArr.count-1 {
        var minPos = i // min position
        for j in i...cloneArr.count-1 {
            if (cloneArr[j] < cloneArr[minPos]) {
                minPos = j
            }
        }

        let temp = cloneArr[i]
        cloneArr[i] = cloneArr[minPos]
        cloneArr[minPos] = temp
    }

    return cloneArr
}

var unsortArr1 = [3,1,6,2,4,7,5]
var sortedArr1 = selectionSort(unsortArr: unsortArr1)
print("test 1: input", unsortArr1)
print("test 1: output", sortedArr1)

print("---------------------")

var unsortArr2 = [9,5,8,2,3,9,9,10,4]
var sortedArr2 = selectionSort(unsortArr: unsortArr2)
print("test 2: input", unsortArr2)
print("test 2: output", sortedArr2)
