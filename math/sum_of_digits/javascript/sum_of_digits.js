const sumOfDigits = number => String(number).split('').reduce((sum, value) => sum + +value, 0);

module.exports = sumOfDigits;
