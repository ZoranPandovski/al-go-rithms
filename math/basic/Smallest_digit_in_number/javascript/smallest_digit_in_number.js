function smallest_digit_in_number(num) {
	num = num.toString();
	var a = num.split("");
	var min = a[0];
	a.forEach(element => {
		if(min > element) {
			min = element;
		}
	});
	return min;
}

// Example
var number = 37847862;
var digit = smallest_digit_in_number(number);
console.log(digit); // Expected output: 2