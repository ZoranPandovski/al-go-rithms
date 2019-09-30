// In this puzzle there is a tower with a stack of rings on it with the largest on the bottom up to the smallest on top
// Goal is to move all the rings to the destination tower
// Rules are that a smaller ring can NEVER be under a larger ring and you are given one spare tower to use

// Function takes in num (the number or rings on the origin tower)
// plus the tower names as strings (initial call must be in order of 'origin', 'destination', 'spare')
// and prints out the steps required to solve this puzzle

function tower(num,col1,col2,col3){
	// this is to prevent user from inputing 0 or negative numbers
	if(num < 1){
		console.log("There are no rings");
		return;
	}
	// this is the base case, where you simply have just one ring to move
	if(num == 1) { 
		console.log("move " + col1 + " to " + col2);
		return;
	}
	// else we move the 'towers' around and make our recursive calls
	else {
		tower(num-1,col1,col3,col2);
		tower(1,col1,col2,col3);
		tower(num-1,col3,col2,col1);
	}
}

// test cases
console.log("test case with 0 rings");
tower(0, "origin", "destination", "spare");
console.log("Only 1 ring");
tower(1, "origin", "destination", "spare");
console.log("2 rings");
tower(2, "origin", "destination", "spare");