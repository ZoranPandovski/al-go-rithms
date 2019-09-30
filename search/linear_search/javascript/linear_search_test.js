// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const linearSearch = require('./linear_search');

describe("Linear Search", () => {

  it('search in small array', () => {

    [
      [ [1, 2, 3, 4], 2, 1],
      [ [1, 2, 3, 4], 4, 3],
      [ [1, 2, 3, 4], 5, -1],
      [ [1, 3, 4, 5, 6], 2, -1 ]
    ].forEach( test => {
      let ts = process.hrtime()
      expect(linearSearch(test[0], test[1])).toBe(test[2]);
      ts = process.hrtime(ts);
      console.log(`Search took: ${ts[0] * 1e9 + ts[1] } ns`);
    });
  })

});
