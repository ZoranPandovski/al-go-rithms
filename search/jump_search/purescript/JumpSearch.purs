module JumpSearch where

import Data.Maybe
import Data.Array (index, length)
import Data.Int (floor, toNumber)
import Math (sqrt, min)
import Prelude (otherwise, (&&), (<), (<=), (-), (+), (>=), (==), (>))


--Example List
alist :: Array Int
alist = [1, 3, 5, 7, 9, 11, 13, 15, 17]

-- use Jump Search t find a value
findVal :: Array Int -> Int -> Int
findVal list val = doJumpSearch list val 0 0 (getIndexVal list 0)

findJump :: forall t2. Array t2 -> Int
findJump list = floor (sqrt (toNumber (length list)))

getIndexVal :: Array Int -> Int -> Maybe Int
getIndexVal list left = (index list left)

doJumpSearch :: Array Int -> Int -> Int -> Int -> Maybe Int -> Int
doJumpSearch list val left right (Just leftIndex) | left < (length list) && (leftIndex <= val) = confirmSection list val left (floor (findRight list left)) (getIndexVal list left) (getIndexVal list (floor (findRight list left))) 
								 		   		  | otherwise = (0-1)
doJumpSearch list val left right Nothing = (0-1)							 		  

findRight :: Array Int -> Int -> Number
findRight list left = min (toNumber(length list) - 1.0) (toNumber (left + (findJump list)))

confirmSection :: Array Int -> Int -> Int -> Int -> Maybe Int -> Maybe Int -> Int
confirmSection list val left right (Just leftIndex) (Just rightIndex) | (leftIndex <= val) && (val <= rightIndex) = checkValInSection list val left right (getIndexVal list left)
								   			 						  | otherwise = doJumpSearch list val (left + (findJump list)) right (getIndexVal list (left + (findJump list)))
confirmSection list val left right _ Nothing = (0-1)
confirmSection list val left right Nothing _ = (0-1)
										 							   			

checkValInSection :: Array Int -> Int -> Int -> Int -> Maybe Int -> Int
checkValInSection list val left right (Just leftIndex) | left >= (length list) = (0-1)
											  		   | leftIndex > val = (0-1)
											  		   | otherwise = findPosition list val left (newRight list right) (getIndexVal list left)
checkValInSection list val left right Nothing = (0-1)									  			

newRight :: Array Int -> Int -> Int
newRight list right = floor (min (toNumber(length list) - 1.0) (toNumber right))

findPosition :: Array Int -> Int -> Int -> Int -> Maybe Int -> Int
findPosition list val left right (Just leftIndex) | (left <= right) && (leftIndex <= val) = confirmPosition list val left right (getIndexVal list left)
								 		   		  | otherwise = (0-1)
findPosition list val left right Nothing = (0-1)

confirmPosition :: Array Int -> Int -> Int -> Int -> Maybe Int -> Int
confirmPosition list val left right (Just leftIndex) | leftIndex == val = left
											 		 | otherwise = findPosition list val (left + 1) right (getIndexVal list (left + 1))
confirmPosition list val left right Nothing = (0-1)	




