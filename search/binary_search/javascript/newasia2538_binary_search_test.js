// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const binarySearch = require('./newasia2538_binary_search');

describe("Binary Search", () => {
    const array = [18,3,4,60,10,11,14,12];
  it('can find correct value in array', () => {
    [11, 4, 3].forEach( test => {
      expect(binarySearch(array, test)).toBe(array.indexOf(test));
    });
  });

  it('not found correct value in array', () => {
    [1, 4120, 11.5].forEach( test => {
      expect(binarySearch(array, test)).toBe(-1);
    });
  });

});
