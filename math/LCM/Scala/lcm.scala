object lcmSingleton {

    def lcm(a: Int, b: Int): Int = {
        def gcd(a: Int, b: Int): Int = {
            if(b == 0) a
            else gcd(b, a % b)
        }
        a * b / gcd(a, b)
    }
}