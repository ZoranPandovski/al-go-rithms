// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const russianPeasant = require('./rusian_peasant');

describe("Rusian peasant", () => {
  
  [
    [5, 5, 25],
    [1, 8, 8],
    [13, 78, 1014],
    [7, 67, 469]
  ].forEach( test => {
    it(`${test[0]} x ${test[1]}`, () => {
      expect(russianPeasant(test[0], test[1])).toBe(test[2]);
    });
  });

});
