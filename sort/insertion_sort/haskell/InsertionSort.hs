module InsertionSort (insertionSort) where
import Data.List (insert)
insertionSort :: Ord a => [a] -> [a]
insertionSort l = foldr insert [] l
