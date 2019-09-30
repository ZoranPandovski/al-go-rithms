// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const fibonacci = require('./fibonacci');

describe("Fibonacci", () => {
  // number1, number2, GDC
  fibonacciNumbers = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610];
  
  [1, 3, 7, 10, 14].forEach( n => {
    it(`${n} number`, () => {
      expect(fibonacci(n)).toBe(fibonacciNumbers[n-1]);
    });
  });
});
