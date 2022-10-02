//recursive version of the euclidean algorithm

function gcd(a, b) {
	if (b==0) {
		return a;
	}
	else {
		return gcd(b, a%b);
	}
}

//tests

console.log(gcd(12,8));
//4

console.log(gcd(54,24));
//6

console.log(gcd(48,180));
//12

console.log(gcd(3,5));
//1
