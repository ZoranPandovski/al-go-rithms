// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const lps = require('./longestPalindromicSubsequence');

describe("Longest Palindromic Subsequence", () => {

  it('should find the longest palindromic subsequence in a short string', () => {
    const X = "ABBDCACB";
    
  let ts = process.hrtime()
  expect(lps(X, 0, X.length-1)).toBe(5);
  ts = process.hrtime(ts);
  console.log(`Search took: ${ts[0] * 1e9 + ts[1] } ns`);
    
  })

});