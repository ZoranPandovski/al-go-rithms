(function(){
"use strict"

const addOne = function(testCases, numbers) {
	if (numbers.length !== testCases){
		return "Error: number of testcases expected is "+testCases+"; number of numbers given is "+numbers.length;
	}

	var outputs = [];
	for (var i = 0; i < testCases; i++) {
		outputs[i] = 0;
	}

	var lastDigit = 0;
	var multiplier = 1;
	// i = 1;
    for (var i = 0; i < testCases; i++) {
    	while (numbers[i] != 0) {
	    	lastDigit = parseInt(numbers[i]%10)+1;
	    	outputs[i] = outputs[i] + (lastDigit*multiplier);
	    	multiplier = multiplier*10;
	    	numbers[i] = parseInt(numbers[i]/10);
	    }
	    lastDigit = 0;
	    multiplier = 1;
    }

    return outputs;

}

module.exports = addOne;

})();  