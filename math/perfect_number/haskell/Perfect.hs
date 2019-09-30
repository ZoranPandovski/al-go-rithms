
module Perfect where

import Data.List

isperfect :: Int -> Bool
isperfect a = a == (sum $ init $ filter (\x-> f a x ) [1..a])

f :: Int -> Int -> Bool
f a b = rem a b == 0

-- isperfect2 
-- only makes a list up to sqrt i.e.  a = 144  list made is [1,2,3,4,5,6,7,8,9,10,11,12] 
-- difference is noticable for inputs 33550336 
isperfect2 :: Int -> Bool
isperfect2 a = (sum $ finalDivisors) == a
    where root          = ceiling $ sqrt $ fromIntegral  a
          lowerDivisors = filter (\x-> f a x ) [1..root]
          upperDivisors = tail $ map (div a)lowerDivisors    -- tail because we dont want to include the number itself
          finalDivisors = union lowerDivisors upperDivisors
