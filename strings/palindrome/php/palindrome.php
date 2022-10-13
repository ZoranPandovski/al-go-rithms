<?php

function isPalindrome($word) {
    $reversedWord = strrev($word);
    return ($word == $reversedWord) ? true : false;
}

$word = 'rainbow';

if(isPalindrome($word)) {
    echo $word . " is a palindrome";
} else {
    echo $word . " is not a palindrome";
}