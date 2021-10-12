<?php

function rearrangeWord($word) {
    $arrStr = str_split(trim(strtolower($word)));
    sort($arrStr);
    return implode($arrStr);
}

function isAnagram($word1, $word2) {
    if (rearrangeWord($word1) === rearrangeWord($word2)) {
        return true;
    }
    return false;
}

isAnagram('mother', 'father');
isAnagram('Dusty', 'Study');
isAnagram('Eleven plus two', 'Twelve plus one');