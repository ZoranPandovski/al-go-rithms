func bubbleSort(unsortArr: [Int]) -> [Int] {
    var cloneArr = unsortArr

    for i in 0...cloneArr.count-2 {
        for j in 0...cloneArr.count-2 {
            if (cloneArr[j] > cloneArr[j+1]) {
                let temp = cloneArr[j]
                cloneArr[j] = cloneArr[j+1]
                cloneArr[j+1] = temp
            }
        }
    }

    return cloneArr
}

var unsortArr1 = [3,1,6,2,4,7,5]
var sortedArr1 = bubbleSort(unsortArr: unsortArr1)
print("test 1: input", unsortArr1)
print("test 1: output", sortedArr1)

print("---------------------")

var unsortArr2 = [9,5,8,2,3,9,9,10,4]
var sortedArr2 = bubbleSort(unsortArr: unsortArr2)
print("test 2: input", unsortArr2)
print("test 2: output", sortedArr2)
