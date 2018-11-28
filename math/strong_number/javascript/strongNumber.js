const factorial = n => (n <= 1) ? 1 : n * factorial(n-1);

/**
 * Checks if a number is equal to the sum of the factorials of its digits.
 *
 * @param num The number to check
 * @returns boolean Whether the number is strong or not.
 */
const checkStrongNum = num => {  
    var sum = 0;
    var temp = num;
    while (temp != 0) {
        digit = temp % 10;
        temp = Math.trunc(temp/10);
        sum += factorial(digit); 
    }
    return (sum == num);
}

module.exports = checkStrongNum;
