// Jasmine test for the flatten algo - harshildp

const flatten = require('./flatten');

describe('flatten', function () {
  it('proper output with defined output', function () {
    expect(flatten([1, [2, 3], [[[[[1]]], [2, [3]], 3]], [[4, [5]], 6], []])).toBe([1, 2, 3, 1, 2, 3, 3, 4, 5, 6]);
  });
  
  it('proper output with undefined input', function () {
    expect(flatten([])).toBe([]);
  });
});
