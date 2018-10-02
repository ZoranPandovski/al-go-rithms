fibonaccilist = [ fibonaccilist x | x <- [0..]]

fibonaccilist 0 = 0
fibonaccilist 1 = 1
fibonaccilist n = fiblist !! (n-1) + fiblist !! (n-2)

main = print (take 10 fiblist)