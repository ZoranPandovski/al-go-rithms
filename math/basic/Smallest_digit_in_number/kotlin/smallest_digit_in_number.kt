fun main(args: Array<String>) {
    println("Hello, world!"+smallest_digit(123))
}

fun smallest_digit( n: Int) : Int{
    var n = n
    var min = n%10
    n/=10
    while(n!=0){
        if(min>n%10)
        min=n%10
        
        n/=10
    }
    return min
}
