<?php

/* 
 * A palindrome is a word, phrase, or sequence that reads the same 
 * backward as forward, e.g., madam or nurses run.
 */
class Palindrome
{
    public static function isPalindrome($word)
    {
        return strtolower(strrev($word)) == strtolower($word);
    }
}

echo Palindrome::isPalindrome('Deleveled');
