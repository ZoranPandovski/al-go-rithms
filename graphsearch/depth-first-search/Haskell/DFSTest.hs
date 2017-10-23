module DFSTest.Main (main) where

import DFS

-- Acts as IO interface
main :: IO ()
main = do
    if test
    then putStrLn "List sorted correctly"
    else putStrLn "Error: List did not sort correctly"

-- Unit test
test :: Bool
test = "ABCDEFGHI" == traverseDFS createTree
  where
    createTree = Node 'A'
                (Node 'B'
                    (Node 'C' Empty Empty)
                    (Node 'D' Empty Empty)
                )
                (Node 'E'
                    (Node 'F' Empty Empty)
                    (Node 'G' Empty (Node 'H'
                        (Node 'I' Empty Empty)
                        Empty
                    ))
                )
