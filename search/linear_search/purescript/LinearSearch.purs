module LinearSearch where

-- Written and tested in in Purescript 0.12
import Prelude ((+), (==))
import Data.Array 
import Data.Maybe (Maybe(..))

exampleSearch :: Maybe Int 
exampleSearch = linear_Search [29,24,5,7,69,1,56] 5
--should answer Just 2

linear_Search :: Array Int -> Int -> Maybe Int 
linear_Search arr value = search arr value 0 

search :: Array Int -> Int -> Int -> Maybe Int 
search arr value pos = case uncons arr of                -- uncons splits array into head and tail 
        Just { head: x, tail: xs } ->  
            if x == value then Just pos                  -- if found return the position
                          else search xs value (pos+1)   -- If its not found, recursively search 
        Nothing -> Nothing
