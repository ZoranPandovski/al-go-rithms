<?php

function pigeonhole_sort($array) {
    $sortArray = [];

    $minVal = min($array);
    $maxVal = max($array);
    $range = $maxVal - $minVal + 1;

    for($i = 0; $i < $range; $i++) {
        $holes[$i] = 0;
    }

    foreach($array as $item) {
        $holes[$item - $minVal] += 1;
    }

    for($i = 0; $i < count($holes); $i++) {
        while ($holes[$i] > 0) {
            array_push($sortArray, $i + $minVal);
            $holes[$i] -= 1;
        }
    }

    return $sortArray;

}

// Example usage, input array
print_r(pigeonhole_sort([8, 5, 19, 13, 11]));