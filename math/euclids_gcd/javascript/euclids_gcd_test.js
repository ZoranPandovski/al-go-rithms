// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const euclidsGcd = require('./euclids_gcd');

describe("Eucid's Greatest Common Divisor finder", () => {
  // number1, number2, GDC
  [
    [ 1, 10, 1 ],
    [ 2, 4, 2 ],
    [ 2, 9, 1 ],
    [ 37, 91, 1 ],
    [ 5, 10, 5 ],
    [ 6, 9, 3 ],
    [12210, 8352, 6]
  ].forEach(test => {
    it(`GDC of ${test[0]} and ${test[1]}`, () => {
      expect(euclidsGcd(test[0], test[1])).toBe(test[2]);
    });
  });
});
