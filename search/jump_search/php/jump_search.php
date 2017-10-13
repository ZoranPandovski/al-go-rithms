<?php

function jumpSearch(array $elements, $number) {
    $n = count($elements);
    
    // Finding block size to be jumped
    $step = sqrt($n);
    
    // Finding the block where element is
    // present (if it is present)
    $prev = 0;
    while($elements[min($step,$n)-1] < $number)
    {
        $prev = $step;
    	$step += sqrt($n);
    	if($prev >= $n)
        	return -1;
    }
    
    // Doing a linear search for x in block
    // beginning with prev.
    while($elements[$prev] < $number)
    {
        $prev++;
        
        // If we reached next block or end of
        // array, element is not present.
        if ($prev === min($step, $n))
            return -1;
    }
    
    // If element is found
    if ($elements[$prev] === $number)
        return $prev;
    
    return -1;
}
function jumpSearchTest() {
    $elements = [1,2,3,5,21,42,63,256,1024];
    $num = 63;
    $result = jumpSearch($elements, $num);
    
    if ($result === -1) {
        echo "Element not found.";
    } else {
        echo "Element found.";
    }
}
jumpSearchTest();

?>
