<?php

function linearSearch(array $elements, $number) {
    for($i = 0; $i < count($elements); $i++)
        if($elements[$i] === $number)
        	return $i;
    return -1;
}
function linearSearchTest() {
    $elements = [2,3,5,-12,70,123,256,10,-53,11];
    $num = 10;
    $result = linearSearch($elements, $num);
    
    if ($result === -1) {
        echo "Element not found.";
    } else {
        echo "Element found.";
    }
}
linearSearchTest();

?>
