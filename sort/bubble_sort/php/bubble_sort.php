<?php

function bubbleSort(array $elements)
{
    $elementCount = count($elements);

    for ($i = 1; $i < $elementCount; $i++) {
        for ($j = 0; $j < $elementCount - $i; $j++) {
            if ($elements[$j] > $elements[$j + 1]) {
                $temp = $elements[$j];
                $elements[$j] = $elements[$j + 1];
                $elements[$j + 1] = $temp;
            }
        }
    }

    return $elements;
}
