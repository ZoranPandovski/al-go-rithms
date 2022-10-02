//the most efficient way to calculate lcm of a and b is their product divided by their greatest common divisor (gcd)

function gcd(a, b) {
	if (b==0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

function lcm(a, b) {
	return ((a*b) / (gcd(a,b)));
}

//tests

console.log(lcm(2,3));
//6

console.log(lcm(4,3));
//12

console.log(lcm(2,9));
//18

console.log(lcm(4,6));
//12
