<?php

	for($i = 99; $i >= 0; $i--) {
		$bottles = $i;
		$remaining_bottles = $i-1; 
		if($bottles > 1){
			echo $bottles . " bottles of beer on the wall, ".$bottles." bottles of beer.\n";
		}elseif ($bottles==1) {
			echo $bottles . " bottle of beer on the wall, ".$bottles." bottle of beer.\n"; 
		}else{
			echo "No more bottles of beer on the wall, no more bottles of beer.\n"; 
		}
		if($remaining_bottles > 1){
			echo "Take one down and pass it around, ".$remaining_bottles." bottles of beer on the wall.\n";
		}elseif ($remaining_bottles == 1) {
			echo "Take one down and pass it around, ".$remaining_bottles." bottle of beer on the wall.\n";
		}elseif ($remaining_bottles==0){
			echo "Take one down and pass it around, no more bottles of beer on the wall.\n";
		}else{
			echo "Go to the store and buy some more, 99 bottles of beer on the wall.\n";		
		}
	}
?>

