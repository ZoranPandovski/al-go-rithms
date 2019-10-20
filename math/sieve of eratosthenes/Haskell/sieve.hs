sieve :: [Integer] -> [Integer]
sieve [] = []
sieve (x:xs)
        | length xs == 0 = x : sieve (xs \\ [x])
        | otherwise = x : sieve (xs \\ [x, x + x..maximum xs])