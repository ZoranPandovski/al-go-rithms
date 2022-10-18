<?php

// Returns length of the longest word in input string
function longest_word_length($string) {
    $words = explode(' ', $string);
    $length = 0;
    
    foreach($words as $word) {
        if(strlen($word) > $length) {
            $length = strlen($word);
        }
    }

    return $length;
}

// Example usage calling longest_word_length

print_r(longest_word_length('This is the longest word in the sentence'));