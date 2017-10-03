module InsertionSortTest.Main (main) where
import Data.List (sort)

import InsertionSort (insertionSort)

main :: IO ()
main = do
    if test
    then putStrLn "List sorted correctly"
    else putStrLn "Error: List did not sort correctly"

test :: Bool
test = sort list == insertionSort list
  where
    list = [12,3,55,1,2,7,4]
