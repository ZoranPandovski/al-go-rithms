<?php

class Palindrome
{
    public static function isPalindrome($word)
    {
        return strtolower(strrev($word)) == strtolower($word);
    }
}

echo Palindrome::isPalindrome('Deleveled');