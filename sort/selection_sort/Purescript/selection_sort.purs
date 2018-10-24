module SelectionSort where

import Prelude
import Data.Array (cons, delete, index, length)
import Data.Maybe (Maybe(..))

unsortedList :: Array Int
unsortedList = [11, 25, 12, 22, 64]
--length = 5

runSelectionSort :: Array Int -> Array Int
runSelectionSort arr | arr == [] = [2]
					 | otherwise = iterateList arr [] 1 (isItEmpty (index arr 0))

returnMin :: Int -> Maybe Int -> Int
returnMin a (Just b) = min a b
returnMin _ Nothing = 1

iterateList :: Array Int -> Array Int -> Int -> Int -> Array Int
iterateList arr newArr pos minVal | pos < length(arr) = iterateList arr newArr (pos + 1) (returnMin minVal (index arr pos))
								  | otherwise = createNewArr arr newArr pos minVal

createNewArr :: Array Int -> Array Int -> Int -> Int -> Array Int
createNewArr arr newArr pos minVal | length(arr) > 0 = iterateList (delete minVal arr) (cons minVal newArr) 1 (isItEmpty (index (delete minVal arr) 0))
								   --| (length(arr) == 1 = (cons minVal newArr)
								   | otherwise = newArr

isItEmpty :: Maybe Int -> Int						
isItEmpty (Just val) = val
isItEmpty Nothing = 0