/// Recursive factorial function
let rec fac (n:int) : int = // int -> int, integer input to integer output
    if n <= 1 // stop function if n is equal to or smaller than 1
    then 1 // return 1 if, if-statement is true
    else n * (fac (n - 1)) //recursion goes on here

/// Test the function
let test_fac() = 
    let prompt n =
        printf "%s: " n
        System.Console.ReadLine() //read user input
    let a = prompt "n"
    printfn "factorial: %i" (fac (int a)) //print the return of function fac with input a

test_fac() //run function

//printfn "%i" (fac 5)