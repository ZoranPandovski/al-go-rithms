object EuclidGCD {
  def gcd(a: Int, b: Int): Int = {
    if (a == 0) b else gcd(b % a, a)
  }

  def main(args: Array[String]) {
      println(gcd(50, 40))
  }
}