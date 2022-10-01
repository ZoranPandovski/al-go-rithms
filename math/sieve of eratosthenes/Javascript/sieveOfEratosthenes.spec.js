// tests are written in Jest
// For information on how to run them, see https://jestjs.io/docs/en/getting-started.html
const sieve = require('./sieveOfEratosthenes');

test('negative value yields empty list', () => {
  expect(sieve(-10)).toStrictEqual([]);
});

test('input 0 yields empty list', () => {
  expect(sieve(0)).toStrictEqual([]);
});

test('input 1 yields empty list', () => {
  expect(sieve(1)).toStrictEqual([]);
});

test('input 2 yields [2]', () => {
  expect(sieve(2)).toStrictEqual([2]);
});

test('valid inputs yield accurate results', () => {
  expect(sieve(6)).toStrictEqual([2, 3, 5]);
  expect(sieve(20)).toStrictEqual([2, 3, 5, 7, 11 ,13, 17, 19]);
  expect(sieve(40)).toStrictEqual([2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,37]);
});
