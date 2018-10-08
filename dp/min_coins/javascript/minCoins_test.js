// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const minCoins = require('./minCoins');

describe("Minimum number of coins", () => {

  it('should find least number of coins to make up change', () => {    
	var ts = process.hrtime()
	expect(minCoins([9,6,5,1], 11)).toBe(2);
	ts = process.hrtime(ts);
	console.log(`Search took: ${ts[0] * 1e9 + ts[1] } ns`);
	
	ts = process.hrtime()
	expect(minCoins([1,5,10,25,50], 199)).toBe(10);
	ts = process.hrtime(ts);
	console.log(`Search took: ${ts[0] * 1e9 + ts[1] } ns`);
  })

});