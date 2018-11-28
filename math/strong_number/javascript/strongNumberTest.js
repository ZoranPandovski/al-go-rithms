/**
 * How to use:
 * Type node strongNumberTest.js [num] into the command line.
 */

const checkStrongNum = require('./strongNumber.js');

var num = parseInt(process.argv[2]);
var testResult = checkStrongNum(num);
var formatString = `${num} is${testResult ? '' : ' not'} a strong number.`
console.log(formatString);
