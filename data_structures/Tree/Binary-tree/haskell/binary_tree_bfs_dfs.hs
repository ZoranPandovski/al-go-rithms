-- Tree DS
data Tree a = Empty | Node a (Tree a) (Tree a) deriving (Show)

-- DFS
traverseDFS :: Tree a -> [a]
traverseDFS Empty = []
traverseDFS (Node a l r) = a : (traverseDFS l) ++ (traverseDFS r)

-- BFS
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
