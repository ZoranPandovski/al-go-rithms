// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const fibonacci = require('./mattgd_fibonacci');

describe("Fibonacci by mattgd", () => {
  // number1, number2, GDC
  fibonacciNumbers = [1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610];
  
  [1, 2, 5, 8, 14].forEach( n => {
    it(`${n} number`, () => {
      expect(fibonacci(n)).toEqual(fibonacciNumbers.slice(0, n));
    });
  });
});
