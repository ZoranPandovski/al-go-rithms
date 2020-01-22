import java.lang.Math

/*
 * The code below calculates N-th fibonacci number by O(1)
 * Such speed is achieved by using the Binet's formula which is
 * fib(n) = (phi^n - psi^n) / sqrt(5)
 * where
 * phi = (1 + sqrt(5)) / 2 and psi = (1 - sqrt(5)) / 2
 * But in code we compute fib(n) as
 * fib(n) = round(phi^n) / sqrt(5)
 * because when n -> inf: abs(psi^n) -> 0
 * When n is small this formula is innacurate because
 * we are computing in double and float and they aren't the exact values that we have in Math
 * Because of the same reasons we may have slightly innacurate values with small n.
 */

fun fib(n: Int): Long {
    val phi = (1 + Math.sqrt(5.0)) / 2
    return (Math.round(Math.pow(phi, n.toDouble())) / Math.sqrt(5.0)).toLong()
}

fun main(args: Array<String>) {
    val n = 50
    println(fib(n))
}