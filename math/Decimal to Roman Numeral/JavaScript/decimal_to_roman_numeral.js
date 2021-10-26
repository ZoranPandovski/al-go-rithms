function roman(num){
	res = "";
	if (num >= 4000){
		return "There is not a representation for roman numerals greater than 3999"
	}
	else if(num < 0) {
		return "There is not a representation for negative roman numerals";
	}
	else if (num == 0) {
		return " ";
	}
	romValues=["M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"]
	decValues=[1000,900,500,400,100,90,50,40,10,9,5,4,1]
	
	pos = 0
	
	while (num > 0) {
		if(num >= decValues[pos]) {
			res = res + romValues[pos];
			num = num - decValues[pos];
		}
		else {
			pos = pos + 1;
		}
	}
	return res;
}

//tests

console.log(roman(10));
//X

console.log(roman(3449));
//MMMCDXLIX

console.log(roman(99));
//XCIX

console.log(roman(1010));
//MX

console.log(roman(9567));
//There is not a representation for roman numerals greater than 3999