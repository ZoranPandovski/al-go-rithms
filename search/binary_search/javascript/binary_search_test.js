// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const binarySearch = require('./binary_search');

describe("Binary Search", () => {

  it('search in small array', () => {
    const arr = [1,3,5,6,8,11,14,122];

    [11, 1, 122, 14].forEach( test => {
      let ts = process.hrtime()
      expect(binarySearch(arr, test)).toBe(arr.indexOf(test));
      ts = process.hrtime(ts);
      console.log(`Search took: ${ts[0] * 1e9 + ts[1] } ns`);
    });
  })

  it('not found in array', () => {
    const arr = [1,3,5,6,8,11,14,122];
    [2,4,7].forEach( test => {
      let ts = process.hrtime()
      expect(binarySearch(arr, test)).toBe(false);
      ts = process.hrtime(ts);
      console.log(`Search took: ${ts[0] * 1e9 + ts[1] } ns`);
    });
  })

});
