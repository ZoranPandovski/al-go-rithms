/**
 * Catalan Number Generator
 *
 * @author Osipov Sergei 
 * @license MIT
 *
 * @param {Number} n input number
 *
 * @example
 * // const index = 3;
 * // console.log(`Catalan number #${index} is ${catalanNumber(index)}`);
 *
 * @returns {Number}
 */
const catalanNumber = (n) => {
	// unsigned int
	if ((n ^ 0) !== n || n <= 0) {
		return 0;
	}
	if (n === 1) {
		return 1;
	}
	return (4*n-2)/(n+1)*catalanNumber(n-1);
}

module.exports = catalanNumber;