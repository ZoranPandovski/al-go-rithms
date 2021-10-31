<?php

function shellSort($array) {
    for ($j = count($array); $j > 0; $j = intval($j/2)) { 
        for ($i = $j; $i < count($array); $i++) { 
            $k = $array[$i];
            for ($l = $i; $l >= $j && $k < $array[$l - $j]; $l -= $j) { 
                $array[$l] = $array[$l - $j];
            }

            $array[$l] = $k;
        }
    }

    return $array;
}

$sorted = shellSort([25, 18, 23, 1, 11, 20, 5, 24, 16, 13]);
print_r($sorted);