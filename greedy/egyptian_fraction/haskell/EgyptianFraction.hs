module EgyptianFraction where
import Data.Ratio (Ratio, (%), denominator, numerator)
 
egyptianFraction :: Integral a => Ratio a -> [Ratio a]
egyptianFraction n
  | n < 0 = map negate (egyptianFraction (-n))
  | n == 0 = []
  | x == 1 = [n]
  | x > y = (x `div` y % 1) : egyptianFraction (x `mod` y % y)
  | otherwise = (1 % r) : egyptianFraction ((-y) `mod` x % (y * r))
  where
    x = numerator n
    y = denominator n
    r = y `div` x + 1
