<?php

include "shaker_sort.php";

$array = [42, 5, 89, 2, 44, 0, 23, -2, 109, 76, 19, -6, 99, 98];
$sorted = shaker_sort($array);

$expected = [-6, -2, 0, 2, 5, 19, 23, 42, 44, 76, 89, 98, 99, 109];
echo ($expected == $sorted) ? 'Array is sorted !!' : 'Array is not sorted as expected';
var_dump('array', $array, 'sorted set', $sorted);