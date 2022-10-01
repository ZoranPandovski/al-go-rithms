<?php

// Tower of Hanoi (n-disk) algorithm in PHP with Display of Pole/rod
// Contents the 3 poles representation
$poles = array(array(), array(), array());

function TOH($n, $A="A", $B="B", $C="C"){
	
	if ($n > 0){
		TOH($n-1, $A, $C, $B);
		echo "Move disk from rod $A to rod $C \n";
		move($A, $C);
		dispPoles();
		TOH($n-1, $B, $A, $C);
	}
	else {
		return;
	}
}

function initPoles($n){
	global $poles;

	for ($i=$n; $i>=1; --$i){
		$poles[0][] = $i;
	}
}


function move($source, $destination){
	global $poles;
	
	// get source and destination pointers
	if ($source=="A") $ptr1=0;
	elseif ($source=="B") $ptr1 = 1;
	else $ptr1 = 2;
	
	if ($destination=="A") $ptr2 = 0;
	elseif ($destination=="B") $ptr2 = 1;
	else $ptr2 = 2;
	
	$top = array_pop($poles[$ptr1]);
	array_push($poles[$ptr2], $top);
}

function dispPoles(){
	global $poles;
	echo "A: [".implode(", ", $poles[0])."] ";
	echo "B: [".implode(", ", $poles[1])."] ";
	echo "C: [".implode(", ", $poles[2])."] ";
	echo "\n\n";
}

$numdisks = 4;
initPoles($numdisks);
echo "Tower of Hanoi Solution for $numdisks disks: \n\n";
dispPoles();
TOH($numdisks);

// This code is contributed by ShreyakChakraborty
?>
