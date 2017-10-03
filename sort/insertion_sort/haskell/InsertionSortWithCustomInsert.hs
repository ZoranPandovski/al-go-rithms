module InsertionSortWithCustomInsert (insertionSort) where

insert :: Ord a => a -> [a] -> [a]
insert x [] = [x]
insert x (y:xs)
    | y < x = y : insert x xs
    | otherwise = x:y:xs

insertionSort :: Ord a => [a] -> [a]
insertionSort l = foldr insert [] l
