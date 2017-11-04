// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const isPrime = require('./is_prime');

describe("Is Prime", () => {

  it("should return false if 1", () => {
    expect(isPrime(1)).toBe(false);
  });

  it("should return true if 2", () => {
    expect(isPrime(2)).toBe(true);
  });

  it("should return true if 3", () => {
    expect(isPrime(3)).toBe(true);
  });

  it("should return false if 4", () => {
    expect(isPrime(4)).toBe(false);
  });

  it("should return true when 31", () => {
    expect(isPrime(31)).toBe(true);
  });
});
