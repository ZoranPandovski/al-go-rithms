import Data.Array

editDistance :: Eq a => [a] -> [a] -> Int
editDistance s1 s2 =  f len1 len2 where
    len1 = length s1
    len2 = length s2
    -- create arrays for random access to items in lists
    arr1 = listArray (1, len1) s1
    arr2 = listArray (1, len2) s2
    bounds = ((0,0), (len1, len2))
    -- create an array to store sub-solutions
    dp = listArray bounds [f i j | (i, j) <- range bounds]
    f 0 j = j
    f i 0 = i
    f i j 
        | arr1!i == arr2!j   = dp ! (i-1, j-1)
        | otherwise          = 1+ minimum [dp!(i-1, j), dp!(i, j-1), dp!(i-1, j-1)] 
