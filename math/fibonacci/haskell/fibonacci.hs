fiblist = [ fibm x | x <- [0..]]

fibm 0 = 0
fibm 1 = 1
fibm n = fiblist !! (n-1) + fiblist !! (n-2)

main = print (take 10 fiblist)