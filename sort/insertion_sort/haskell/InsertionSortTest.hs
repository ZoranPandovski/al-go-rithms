module InsertionSortTest.Main (main) where
import Data.List (sort)

import qualified InsertionSort as StdLibIns
import qualified InsertionSortWithCustomInsert as CustomIns

main :: IO ()
main = do
    putStr "Standard library `insert`: "
    test StdLibIns.insertionSort
    putStr "Custom `insert`: "
    test CustomIns.insertionSort

test :: ([Int] -> [Int]) -> IO ()
test f = if f list == sort list
    then putStrLn "List sorted correctly"
    else putStrLn "Error: List did not sort correctly"
  where list = [12,3,55,1,2,7,4]
