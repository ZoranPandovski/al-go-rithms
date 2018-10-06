import System.IO

-- | TThis function takes a positive integer, divides it by 2 if even or otherwise
-- multipies it by 3 and adds 1 to it. This is done repeatedly until the
-- number is 1. It is conjectured that this function will always terminate.
collatz :: Int -> [Int]
collatz 1 = [1]
collatz n
  | n <= 0      = error "collatz: Undefined for non positive integers"
  | even n      = n : collatz (n `quot` 2)
  | otherwise   = n : collatz (n * 3 + 1)

main :: IO ()
main = do
    putStr "n = "
    hFlush stdout
    n <- readLn :: IO Int
    putStrLn . show . collatz $ n

-- Tests
testCollatzOne      = collatz 1     == [1]
testCollatzTwo      = collatz 2     == [2, 1]
testCollatzThree    = collatz 3     == [3, 10, 5, 16, 8, 4, 2, 1]
testCollatzFour     = collatz 4     == [4, 2, 1]
