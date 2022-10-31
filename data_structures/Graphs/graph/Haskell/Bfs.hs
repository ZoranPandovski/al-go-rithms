import System.Environment (getArgs)

data Tree a = Empty | Node a [Tree a]
      deriving(Show, Read, Eq)
      
bfs :: Tree Int -> Int -> [Tree Int] -> Either Int String
bfs (Node n (sub_tree:tree_list)) val to_visit
                  | val == n = Left n
                  | otherwise = bfs sub_tree val (tree_list ++ to_visit)
bfs Empty val (tree:to_visit_list) = bfs tree val to_visit_list
bfs (Node _ []) _  _   = Right "Incorrect tree format"
bfs  _ _  [] = Right "Value not found"
