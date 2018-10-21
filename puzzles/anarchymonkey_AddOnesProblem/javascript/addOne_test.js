// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const addOne = require('./addOne');

describe("", () => {

  it('should add one to each digit in the number', () => {    
  	expect(addOne(3,[1000,9999,29])).toEqual([2111,11110,40]);
  	expect(addOne(5,[2000,1111,1234,91,79])).toEqual([3111,2222,2345,102,90]);
  });

  it('should return an error message', () => {
  	expect(addOne(10, [88])).toBe("Error: number of testcases expected is 10; number of numbers given is 1")
  });

});