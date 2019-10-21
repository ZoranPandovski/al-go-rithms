{-

You must print the lyric of the song as follows:

99 bottles of beer on the wall, 99 bottles of beer.
Take one down and pass it around, 98 bottles of beer on the wall.
98 bottles of beer on the wall, 98 bottles of beer.
Take one down and pass it around, 97 bottles of beer on the wall.
...
...
...
2 bottles of beer on the wall, 2 bottles of beer.
Take one down and pass it around, 1 bottle of beer on the wall.
1 bottle of beer on the wall, 1 bottle of beer.
Take one down and pass it around, no more bottles of beer on the wall.
No more bottles of beer on the wall, no more bottles of beer. 
Go to the store and buy some more, 99 bottles of beer on the wall.

Here is the general structure of the song:
{n|No more} {bottle|bottles} of beer on the wall, {n|No more} bottles of beer.
Take one down, pass it around, {n - 1|no more} {bottle|bottles} of beer on the wall.

OR

Go to the store and buy some more, 99 more bottles of beer on the wall.
-}

-- printf
import Text.Printf

-- The number of bottles the song begins with
initialBottles = 99

-- Get a single line of the song.
--
-- Takes in a number of bottles and returns a string with the corresponding lyric of that song.
-- For example:
-- lyric 42 == "42 bottles of beer on the wall, 42 bottles of beer.
--              Take one down, pass it around, 41 bottles of beer on the wall."
lyric :: Int -> String
lyric bottles =
    printf "%s on the wall, %s.\n%s" bottlesOfBeer bottlesOfBeer secondLine
    where
        bottlesOfBeer :: String
        bottlesOfBeer = printf "%s %s of beer" (amount bottles) (plural bottles)
        amount n = if n == 0 then "no more" else show n
        plural n = if n == 1 then "bottle" else "bottles"
        secondLine = if bottles == 0
            then "Go to the store and buy some more, 99 more bottles of beer on the wall."
            else printf "Take one down, pass it around, %s %s of beer on the wall." (amount $ bottles - 1) (plural $ bottles - 1)

-- The entire song. Recusively calls `lyric`, counting down from initialBottles to 0, inclusive.
song :: Int -> IO ()
song (-1) = return ()
song n = do
    putStrLn $ lyric n
    song (n - 1)

-- Entry point for the program.
main :: IO ()
main = song initialBottles
