// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const sumOfDigits = require('./sum_of_digits');

describe("Sum of digits", () => {
  
  [
    [ 12345, 15 ],
    [ '111', 3 ],
    [ 111, 3 ],
    [ 521, 8 ],
    [ '111111111123', 15 ],
    [ 817489, 37 ]
  ].forEach( test => {
    it(`sum ${test[0]}`, () => {
      expect(sumOfDigits(test[0])).toBe(test[1]);
    });
  });

});
