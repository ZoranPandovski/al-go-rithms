
module Palindrome where

ispalindrome :: Int -> Bool
ispalindrome a = a == (read ( reverse $ show a ) ::Int)

ispalindromeStrings :: String -> Bool
ispalindromeStrings a = a == (reverse a)
