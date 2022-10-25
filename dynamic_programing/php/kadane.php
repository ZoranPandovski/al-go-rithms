<?php

function kandane_sum($array) {
    $currentSum = 0;
    $maxSum = PHP_INT_MIN;

    for($i = 0; $i < count($array); $i++) {
        $currentSum += $array[$i];

        if($maxSum < $currentSum) {
            $maxSum = $currentSum;
        } elseif($currentSum < 0) {
            $currentSum = 0;
        }
    }
    return $maxSum;
}

// Example usage
echo kandane_sum([-5, -1, 8, -2, 1]);