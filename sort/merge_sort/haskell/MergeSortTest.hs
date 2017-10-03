module MergeSortTest.Main (main) where
import Data.List (sort)

import MergeSort (mergeSort)

main :: IO ()
main = do
    if test
    then putStrLn "List sorted correctly"
    else putStrLn "Error: List did not sort correctly"

test :: Bool
test = sort list == mergeSort list
  where
    list = [12,3,55,1,2,7,4]
