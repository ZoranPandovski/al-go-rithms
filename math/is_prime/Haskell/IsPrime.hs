import System.IO

-- | Checks if a number is prime or not
-- (Note: 0 and 1 are not prime)
isPrime :: Int -> Bool
isPrime 2 = True
isPrime n 
  | n <= 1      = False
  | even n      = False
  | otherwise   = not . any (`divides` n) $ candidateList n
    where
        divides :: Int -> Int -> Bool
        divisor `divides` n = n `mod` divisor == 0

        candidateList :: Int -> [Int]
        candidateList n = takeWhile (<= upperBound n) [3, 5..]
            where
                upperBound :: Int -> Int
                upperBound = ceiling . sqrt . fromIntegral

main :: IO ()
main = do
    putStr "n = "
    hFlush stdout
    n <- readLn :: IO Int
    putStrLn . show . isPrime $ n

-- Tests
testIsPrimeNegative = isPrime (-1)              == False
testIsPrimeZero     = isPrime 0                 == False
testIsPrimeOne      = isPrime 1                 == False
testIsPrimeTwo      = isPrime 2                 == True
testIsPrimeBig      = isPrime 99194853094755497 == True

