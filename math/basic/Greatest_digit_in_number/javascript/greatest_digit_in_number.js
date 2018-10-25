function greatest_digit_in_number(num) {
	num = num.toString();
	var a = num.split("");
	var max = a[0];
	a.forEach(element => {
		if(max < element) {
			max = element;
		}
	});
	return max;
}

// Example
var number = 378478621;
var digit = greatest_digit_in_number(number);
console.log(digit); // Expected output: 8