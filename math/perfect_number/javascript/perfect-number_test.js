// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const isPerfect = require('./perfect-number');

describe("Perfect Number", () => {
  
  [6, 28, 496, 8128].forEach( n => {
    it(`${n} is perfect`, () => {
      expect(isPerfect(n)).toBe(true);
    });
  });

  [16723, 233, 2, 98].forEach( n => {
    it(`${n} isn't perfect`, () => {
      expect(isPerfect(n)).toBe(false);
    });
  });
});
