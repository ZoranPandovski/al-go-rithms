<?php

function twoSum($nums, $target): array
{
    $result = [];
    foreach($nums as $i => $num) {
        $remainder = $target - $num;
        $newNums = $nums;
        unset($newNums[$i]);

        foreach($newNums as $j => $newNum) {
            if($remainder == $newNum) {
                $result[] = $i;
                $result[] = $j;
                break;
            }
        }

        if ($result) break;
    }

    return $result;
}

echo twoSum([2,7,11,15], 9);
echo twoSum([3,2,4], 6);
echo twoSum([3,3], 6);
