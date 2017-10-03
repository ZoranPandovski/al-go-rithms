module Quicksort (quicksort) where
import Data.List (partition)

quicksort :: (Ord a) => [a] -> [a]
quicksort [] = []
quicksort (p:l) =
  (quicksort a) ++ [p] ++ (quicksort b)
  where (a, b) = partition (\x -> x < p) l

