<?php

/**
 * @param $objects
 * @return array
 */
function mergeSort($objects)
{
    if(count($objects) == 1 ) {
        return $objects;
    }

    $middle = count($objects) / 2;
    $left   = array_slice($objects, 0, $middle);
    $right  = array_slice($objects, $middle);
    $left   = mergeSort($left);
    $right  = mergeSort($right);

    return merge($left, $right);
}

/**
 * @param $left
 * @param $right
 * @return array
 */
function merge($left, $right)
{
    $res = [];

    while (count($left) > 0 && count($right) > 0)
    {
        if($left[0] > $right[0]) {
            $res[] = array_shift($right);
        } else {
            $res[] = array_shift($left);
        }
    }

    return array_merge($res, $left, $right);
}