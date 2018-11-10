func isPrime(_ number: Int) -> Bool {
    return number > 1 && !(2.. < number).contains { number % $0 == 0 }
}