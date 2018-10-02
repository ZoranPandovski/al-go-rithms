module EuclidsGCD (gcd') where

--gcd' :: Int -> Int -> Int
gcd' 0 b = b
gcd' a b = gcd' (b `rem` a) a
