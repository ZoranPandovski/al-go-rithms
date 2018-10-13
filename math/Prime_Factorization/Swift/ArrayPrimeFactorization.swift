import Darwin
func primeFactors(of num: Int) -> [Int] {
    var num = num
    var primeFactors: [Int] = []
    while (num % 2 == 0) {
        primeFactors.append(2)
        num /= 2
    }
    var i = 3
    while Double(i) <= sqrt(Double(num)) {
        while num % i == 0 {
            primeFactors.append(i)
            num /= i
        }
        i += 2
    }
    if num > 2 {
        primeFactors.append(num)
    }
    return primeFactors
}
