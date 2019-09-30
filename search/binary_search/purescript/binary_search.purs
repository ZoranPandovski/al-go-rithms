module BinarySearch where
 
import Prelude

import Data.Array (index, length)
import Data.Int (floor, toNumber)
import Data.Maybe (Maybe(..))


--Assume the list is sorted
--return the position of the value otherwise it return -1
binarySearch :: Int -> Array Int -> Int
binarySearch _ [] = (-1)
binarySearch x arr = findMid x arr 0 ((length arr) - 1)

findMid :: Int -> Array Int -> Int -> Int -> Int
findMid x arr low high | low <= high = checkMid (floor (toNumber(low + high))/2) (index arr (floor (toNumber(low + high))/2)) x arr low high
                       | otherwise = (-1)

checkMid :: Int -> Maybe Int -> Int -> Array Int -> Int -> Int -> Int
checkMid pos (Just val) x arr low high 
                          | val < x = findMid x arr (pos + 1) high
                          | val > x = findMid x arr low (pos - 1)
                          | otherwise = pos
checkMid pos Nothing x arr low high = (-1)