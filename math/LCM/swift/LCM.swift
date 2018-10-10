// Greatest Common Denominator
func gcd(a: Int, b: Int) -> Int {
    if b == 0 {
        return a
    }
    return gcd(a: b, b: a % b)
}

// Lowest Common Multiple
func lcm(a: Int, b: Int) -> Int {
    return a * b / gcd(a: a, b: b)
}
