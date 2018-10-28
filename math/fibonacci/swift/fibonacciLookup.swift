
//===----------------------------------------------------------------------===//
// Function
//===----------------------------------------------------------------------===//

// This method calculates Nth fibonacci number using lookup table
func fibonacciLookup(_ n: Int) -> Int {
    var lookup: [Int: Int] = [:]
    func fib(_ n: Int) -> Int {
        if let lookupAnswer = lookup[n] {
            return lookupAnswer
        }
        let answer: Int
        if n == 1 || n == 2 {
            answer = 1
        } else {
            answer = fib(n-2) + fib(n-1)
        }
        lookup[n] = answer
        return answer
    }
    return fib(n)
}

//===----------------------------------------------------------------------===//
// Demo
//===----------------------------------------------------------------------===//

for n in 1...92 {
    print("\(n): \(fibonacciLookup(n))")
}
