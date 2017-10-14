const sumOfDigits = number => String(number).split('').reduce((sum, value) => sum + +value, 0);

// test
[
  [ 12345, 15 ],
  [ '111', 3 ],
  [ 111, 3 ],
  [ 521, 8 ],
  [ '111111111123', 15 ],
  [ 817489, 37 ]
].forEach(test => {
  console.assert(sumOfDigits(test[0]) == test[1]);
})
