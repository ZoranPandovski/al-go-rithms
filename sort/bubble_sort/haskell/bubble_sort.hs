module Bubblesort where
    
    bubblesort::(Ord a)=>[a]->[a]
    bubblesort l = bsort l 0

    swap ::(Ord a)=>[a]->[a]
    swap (x:y:xs)   | x > y = y:swap(x:xs)
                    | otherwise = x:swap(y:xs)
    swap [x] = [x]
    swap [] = []

    bsort::(Ord a)=>[a]->Int->[a]
    bsort l i   | i == (length l) = l
                | otherwise = bsort (swap l) (i + 1)
