fact 0 = 1
fact n = foldl1 (*) [1..n]

main = do
    print(fact 5)

