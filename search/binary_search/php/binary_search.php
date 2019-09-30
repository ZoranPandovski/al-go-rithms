<?php

function binarySearch(array $elements, $number) {
    $left = 0;
    $right = count($elements) - 1;
    
    while ($left < $right) {
        $middle = ($left + $right) / 2;
        
        if ($elements[$middle] < $number) {
            $left = $middle + 1;
        } else {
            $right = $middle;
        }
    }
    
    return $left;
}

function binarySearchTest() {
    $elements = [1,2,3,4,5,6,11,22,33,44,123,256,1024];
    $num = 123;
    $result = binarySearch($elements, $num);
    
    if ($result === null) {
        echo "Element not found.";
    } else if ($elements[$result] !== $num) {
        echo "Element returned by binarySearch method points to different value than expected.";
    } else {
        echo "Element found.";
    }
}

binarySearchTest();
echo PHP_EOL;
