import System.IO

-- | The factorial function takes a non negative integer 'n' and calculates the 
-- product of all the positive integers before n
factorial :: Int -> Int
factorial n
    | n < 0     = error "factorial: Undefined for negative numbers"
    | n == 0    = 1
    | otherwise = n * factorial (n - 1)

main :: IO ()
main = do
    putStr "n = "
    -- Haskell buffers stdout until it is flushed or a new line is printed
    hFlush stdout
    n <- readLn :: IO Int
    putStrLn . show . factorial $ n

-- Tests
testBottomUp :: Int -> Bool
testBottomUp n = product [1..n] == factorial n
testTwenty :: Bool
testTwenty = factorial 20 == 2432902008176640000
