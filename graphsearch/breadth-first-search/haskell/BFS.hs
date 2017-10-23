module BFS where

-- Creating tree ds
data Tree a = Empty | Node a (Tree a) (Tree a) deriving (Show)

-- DFS
traverseBFS :: Tree a -> [a]
traverseBFS tree = tbf [tree]
  where
    tbf [] = []
    tbf xs = map nodeValue xs ++ tbf (concat (map leftAndRightNodes xs))
    
    nodeValue (Node a _ _) = a
    
    leftAndRightNodes (Node _ Empty Empty) = []
    leftAndRightNodes (Node _ Empty b) = [b]
    leftAndRightNodes (Node _ a Empty) = [a]
    leftAndRightNodes (Node _ a b) = [a,b]
