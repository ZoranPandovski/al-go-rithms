<?php

/**
 * @param $objects
 * @return array
 */
function quickSort($objects)
{
    if (count($objects) < 2) {
        return $objects;
    }

    $left  = []; 
    $right = [];

    $pivotKey = key($objects);
    $pivot = array_shift($objects);

    array_walk($objects, function($val, $key) use ($pivot, &$left, &$right) {
        if ($val < $pivot) {
            $left[$key] = $val;
        } else {
            $right[$key] = $val;
        }
    });

    return array_merge(
        quicksort($left),
        [$pivotKey => $pivot],
        quicksort($right)
    );
}
