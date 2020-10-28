//Normal algorithm
func gnomeSort<T: Comparable>(_ array: inout [T]) {
    var i: Int = 1
    var j: Int = 2
    while i < array.count {
        if array[i - 1] <= array[i] {
            i = j
            j += 1
        } else {
            array.swapAt(i - 1, i)
            i -= 1
            if i == 0 {
                i = j
                j += 1
            }
        }
    }
}

//Optimized algorithm
func optimizedGnomeSort<T: Comparable>(_ array: inout [T]) {
    for pos in 1..<array.count {
        gnomeSort(&array, pos)
    }
}

func gnomeSort<T: Comparable>(_ array: inout [T], _ upperBound: Int) {
    var pos = upperBound
    while pos > 0 && array[pos-1] > array[pos] {
        array.swapAt(pos-1, pos)
        pos -= 1
    }
}

//Sample
var array = [10, 8, 4, 3, 1, 10, 9, 0, 2, 7, 5, 6]
optimizedGnomeSort(&array)
//gnomeSort(&array)
print(array)
