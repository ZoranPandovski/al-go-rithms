const digitalRoot = number => {
	while(number > 9){
		const numbers = [...number.toString()].map(n => Number(n))
		number = numbers.reduce((a,b) => a+b)
	}
	return number
}

module.exports = digitalRoot