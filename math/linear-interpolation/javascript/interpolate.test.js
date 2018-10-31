// Can be run directly with node.js.
const assert = require('assert');
const interpolate = require('./interpolate');

let expectedResult;
let actualResult;

expectedResult = 50;
actualResult = interpolate(200, 300, 0, 100, 250);
assert.strictEqual(actualResult, expectedResult);

expectedResult = 1.5;
actualResult = interpolate(0, 10, 6, 1, 9);
assert.strictEqual(actualResult, expectedResult);
