module BFSTest.Main (main) where

import BFS

main :: IO ()
main = do
    if test
    then putStrLn "List sorted correctly"
    else putStrLn "Error: List did not sort correctly"

test :: Bool
test = "ABECDFGHI" == traverseBFS createTree
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
