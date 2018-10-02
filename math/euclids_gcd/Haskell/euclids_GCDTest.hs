module EuclidsGCDTest.Main (main) where

-- Int can be negative, so use Natural numbers only
import Numeric.Natural
import Test.QuickCheck
import EuclidsGCD (gcd')

main :: IO ()
main = do
    if run then putStrLn "Works fine :)"
    else putStrLn "Oh, :("

run :: Bool
run = test 90 45

test :: Int -> Int -> Bool 
test = ((\a b -> gcd a b == gcd' a b) :: Int -> Int -> Bool)

-- cann't figure out how to use quickcheck to automate testing for now, 
