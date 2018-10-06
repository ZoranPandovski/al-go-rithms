func insertionSort(unsortArr: [Int]) -> [Int] {
    var cloneArr = unsortArr

    for i in 1...cloneArr.count-1 {
        for j in (1...i).reversed() {
            if (cloneArr[j-1] > cloneArr[j]) {
                let temp = cloneArr[j]
                cloneArr[j] = cloneArr[j-1]
                cloneArr[j-1] = temp
            }
        }
    }

    return cloneArr
}

var unsortArr1 = [3,1,6,2,4,7,5]
var sortedArr1 = insertionSort(unsortArr: unsortArr1)
print("test 1: input", unsortArr1)
print("test 1: output", sortedArr1)

print("---------------------")

var unsortArr2 = [9,5,8,2,3,9,9,10,4]
var sortedArr2 = insertionSort(unsortArr: unsortArr2)
print("test 2: input", unsortArr2)
print("test 2: output", sortedArr2)