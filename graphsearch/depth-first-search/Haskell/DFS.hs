module DFS where

-- Creating tree ds
data Tree a = Empty | Node a (Tree a) (Tree a) deriving (Show)

-- DFS
traverseDFS :: Tree a -> [a]
traverseDFS Empty = []
traverseDFS (Node a l r) = a : (traverseDFS l) ++ (traverseDFS r)
