// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const radixSort = require('./RadixSort');

describe("Radix Sort", () => {

  [
    [2, 423, 2, 43, 23423, 43, 22, 123],
    [40, 10, 50, 24, 1, 2, 4, 10, 15, 7, 8, 5],
    [5, 3, 21, 1, 4],
    [1, 2, 3, 4, 5],
    [34, 365,546, 2, 23, 5, 457, 876, 365, 342, 56, 78, 990, 8, 7, 54]
  ].forEach( unsort => {
    it(`sort ${unsort.length} elements array`, () => {

      const sorted = unsort.slice();
      sorted.sort((a,b) => a-b);
      
      let ts = process.hrtime()
      const result = radixSort(unsort);
      ts = process.hrtime(ts);
      console.log(`Sort took: ${ts[0] * 1e9 + ts[1] } ns`);

      expect(result).toEqual(sorted);
    });
  })

  it(`sort 200 random elements array`, () => {

    const unsort = [];
    for (let index = 0; index < 100; index++) {
      unsort.push(parseInt(Math.random() * 2000));
    }
    const sorted = unsort.slice();
    sorted.sort((a,b) => a-b);
    
    let ts = process.hrtime()
    const result = radixSort(unsort);
    ts = process.hrtime(ts);
    console.log(`Sort took: ${ts[0] * 1e9 + ts[1] } ns`);

    expect(result).toEqual(sorted);
  });

});
