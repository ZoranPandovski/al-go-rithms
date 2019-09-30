/**
 * Armstrong Number Checker
 *
 * @author Osipov Sergei 
 * @license MIT
 *
 * @param {Number} n input number
 *
 * @example
 * // const number = 1364;
 * // console.log(`is ${number} an Armstrong number? ${isArmstrongNumber(number)}`);
 *
 * @returns {Number}
 */
const isArmstrongNumber = (n) => {
	// unsigned int
	if ((n ^ 0) !== n || n <= 0) {
		return false;
	}
	let a = ''+n;
	let b = a
		.split('')
		.reduce((sum, current) => {
			return sum+=Math.pow(current, a.length)
		}, 0);
	return (a == b);
}

module.exports = isArmstrongNumber;