module BinarySearch where
 
import Control.Lens
import Data.Maybe
 
a :: [Int]
a = [6, 13, 14, 25, 33, 43, 51, 53, 64, 72, 84, 93, 95, 96, 97]
 
bsearch :: Int -> [Int] -> Maybe Int
bsearch _   [] = Nothing
bsearch key xs 
    | key < fromJust val = bsearch key (take (mid-1) xs)
    | key > fromJust val = bsearch key (drop (mid+1) xs)
    | otherwise = val
  where
    mid = floor ((fromIntegral $ (length xs) - 1) / 2)
    val = xs ^? ix mid
