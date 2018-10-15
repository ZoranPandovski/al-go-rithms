// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const studentMark = require('./studentMark');

describe("", () => {

  it('should find how many students have a mark', () => {    
  	expect(studentMark(24, 100)).toBe(24);
  	expect(studentMark(2, 5)).toBe(2);
  })

});