/**
 * Jasmine Tests for Armstrong Number Checker 
 *
 * @author Osipov Sergei 
 * @license MIT
 */
const isArmstrongNumber = require('./isArmstrongNumber');

describe('Armstrong number test', function() {
  it('Armstrong number for correct data', function() {
    expect(isArmstrongNumber(1634)).toBe(true);
  });
  it('not Armstrong number for correct data', function() {
    expect(isArmstrongNumber(1633)).toBe(false);
  });
  it('not Armstrong number for incorrect data', function() {
    expect(isArmstrongNumber({})).toBe(false);
  });
  it('not Armstrong number for number < 0', function() {
    expect(isArmstrongNumber(-1)).toBe(false);
  });
});