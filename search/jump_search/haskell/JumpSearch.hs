
module JumpSearch where

-- [0,1,1,2,3,5,8,13,21,34,55,89,144]
-- [0,1,2,3,4,5,6,7 ,8 ,9 ,10,11,12 ]
-- [.       .        .           .  ]

a :: [Int]
a = [0,1,1,2,3,5,8,13,21,34,55,89,144]

-- Call this function to start algorithm
jumpsearch :: [Int] -> Int -> Maybe Int 
jumpsearch arr num = dojump arr num jump 0
    where jump = (round $ sqrt $ fromIntegral$ length $ arr) -- Jump by the SQRT rounded DOWN

dojump :: [Int] -> Int -> Int -> Int -> Maybe Int
dojump arr num jump index
    | (jump+index) >= (length arr) = linearSearch arr num (index-jump) ((length arr) -1)  -- Either the number is within the last section or is bigger than the highest num in the list   
    | (arr !! index) == num = Just index                                                  -- found the number on a multiple of the jump value 
    | num > (arr !! index) = dojump arr num jump (index + jump)                           -- If num is larger than at current index, jump!  
    | num < (arr !! index) = linearSearch arr num (index-jump) index                      -- if number is smaller than current index, do linear search
    | otherwise = Nothing                                                                 -- Should never get here, if it does, you win a pony.

-- Then just linear search through the list
linearSearch :: [Int] -> Int -> Int -> Int -> Maybe Int
linearSearch arr num index upperbound
    | (arr !! index) == num = Just index                    --
    | (index) == upperbound = Nothing                       -- item does not exist in the section of the array, therefore return Nothing 
    | otherwise = linearSearch arr num (index+1) upperbound -- Go 

