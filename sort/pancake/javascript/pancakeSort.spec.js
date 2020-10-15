// tests are written in Jest
// For information on how to run them, see https://jestjs.io/docs/en/getting-started.html
const pancakeSort = require('./pancakeSort');

test('sorts empty list as empty list', () => {
  expect(pancakeSort([])).toStrictEqual([]);
});

test('sorts single element array', () => {
  expect(pancakeSort([2])).toStrictEqual([2]);
});

test('sorts two element array', () => {
  expect(pancakeSort([4, 2])).toStrictEqual([2, 4]);
});

test('sorts n element array', () => {
  expect(pancakeSort([3, 4, 2])).toStrictEqual([2, 3, 4]);
});

test('handles duplicates', () => {
  expect(pancakeSort([3, 4, 6, 6 ,2])).toStrictEqual([2, 3, 4, 6, 6]);
});

test('handles negative values', () => {
  expect(pancakeSort([3, 4, -6, 6, 2])).toStrictEqual([-6, 2, 3, 4, 6]);
});
