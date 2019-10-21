func fibonacciSearch(arr: [Int], x: Int) -> Int {
    // Fibonacci numbers initialization
    var fib1 = 1
    var fib2 = 0
    var fib = fib1 + fib2
    let n = arr.count
    var offset = -1 // The leftout list for the array
    
    // Find the smallest fibonacci greater than or equal to array length
    while fib < n {
        fib2 = fib1
        fib1 = fib
        fib = fib1 + fib2
    }
    
    while fib > 1 {
        let i = min(offset + fib2, n-1) // Check if fib is a valid index
        
        // If x is greater then the value at index fib2, cut the array from offset to i
        if arr[i] < x {
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i
            
        } else if arr[i] > x { // If x is smaller then the value at index fib2, cut the array after i+1
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1
        } else {
            return i
        }
    }
    
    // Compare last element with x
    if fib1 == x && arr[offset + 1] == x {
        return offset + 1
    }
    
    return -1 // Return -1 if not found element
}

let arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
let x = 100
print ("Found at index: ", fibonacciSearch(arr: arr, x: x))