module MergeSort (mergeSort) where

merge :: Ord a => [a] -> [a] -> [a]
merge xs [] = xs
merge [] ys = ys
merge (x:xs) (y:ys)
    | x < y = x : merge xs (y:ys)
    | otherwise = y : merge ys (x:xs)

mergeSort :: Ord a => [a] -> [a]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort l = let (xs, ys) = splitAt (length l `div` 2) l in
    merge (mergeSort xs) (mergeSort ys)
