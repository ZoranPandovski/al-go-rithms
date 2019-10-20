<?php

public function bubbleSortOptimized($arr, $n) {
  for($i = 0; $i < $n; $i++) {  
    $flag = false;
    for($j = 0; $j < $n - $i - 1; $j++)
     {
        if($arr[$j] > $arr[$j + 1]) {
          $flag        = true;
          $temp        = $arr[$j + 1];
          $arr[$j + 1] = $arr[$j];
          $arr[$j]     = $temp;
        }
     }
    // No Swapping happened, array is sorted
    if(!$flag){ 
       return; 
    } 
 }
}