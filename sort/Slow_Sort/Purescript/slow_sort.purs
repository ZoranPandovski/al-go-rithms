module SlowSort where


import Data.Array (cons, delete, index, length)
import Data.Int (floor, toNumber)
import Data.Maybe (Maybe(..))
import Data.Ord (max)
import Prelude (otherwise, (+), (-), (/), (>), (>=))


unsortedList :: Array Int
unsortedList = [11, 25, 12, 22, 64]

startSlowSort :: Array Int -> Array Int
startSlowSort [] = []
startSlowSort arr = checkArrLength arr []

checkArrLength :: Array Int -> Array Int -> Array Int
checkArrLength arr newArr | length arr > 0 = checkArrLength (remArr (runSlowSort arr 0 (length arr -1) []) arr) (addArr (runSlowSort arr 0 (length arr -1) []) newArr)
						  | otherwise = newArr

remArr :: Maybe Int -> Array Int -> Array Int
remArr (Just a) arr = (delete a arr)
remArr Nothing arr = []						  

addArr :: Maybe Int -> Array Int -> Array Int
addArr (Just a) newArr = (cons a newArr)
addArr Nothing newArr = []						  

runSlowSort :: Array Int -> Int -> Int -> Array Int -> Maybe Int
runSlowSort arr i j newArr | i >= j = (index arr i) 					
						   | otherwise = returnMax (runSlowSort arr i (floor (toNumber(i + j)/2.0)) newArr) (runSlowSort arr ((floor (toNumber(i + j)/2.0))+1) j newArr)

returnMax :: Maybe Int -> Maybe Int -> Maybe Int
returnMax (Just a) (Just b) = Just (max a b)
returnMax _ Nothing = Nothing
returnMax Nothing _ = Nothing