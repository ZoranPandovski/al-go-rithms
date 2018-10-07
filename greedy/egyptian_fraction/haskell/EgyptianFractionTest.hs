module EgyptianFractionTest.Main (main) where
import Data.Ratio ((%))
import EgypitanFraction (egyptianFraction)

main :: IO()
main = do
  if test
  then putStrLn "Correct egyptian fractions returned"
  else putStrLn "Error: Incorrect egyptian fractions"

test :: Bool
test = fraction == egyptianFraction [2 % 5]
    where
      fraction = [1 % 3, 1 % 15]
