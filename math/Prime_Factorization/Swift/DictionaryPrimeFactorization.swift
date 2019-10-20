import Darwin
func primeFactors(of num: Int) -> [Int: Int] {
    var num = num
    var primeFactors: [Int: Int] = [:]
    while (num % 2 == 0) {
        primeFactors[2] = (primeFactors[2] ?? 0) + 1
        num /= 2
    }
    var i = 3
    while Double(i) <= sqrt(Double(num)) {
        while num % i == 0 {
            primeFactors[i] = (primeFactors[i] ?? 0) + 1
            num /= i
        }
        i += 2
    }
    if num > 2 {
        primeFactors[num] = 1
    }
    return primeFactors
}