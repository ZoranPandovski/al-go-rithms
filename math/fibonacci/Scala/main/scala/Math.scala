import scala.annotation.tailrec

object Math {

  /**
    * A tail recursive function to calculate n th fibonacci number
    *
    * @param n fibonacci to compute
    * @param a fib(n - 2)
    * @param b fib(n - 1)
    * @return fibonacci of n
    */
  @tailrec
  def fibonacci(n: Int, a: Int = 0, b: Int = 1): Int = n match {
    case 0 => a
    case 1 => b
    case _ => fibonacci(n - 1, b, a + b)
  }
}
