/**
 * Jasmine Tests for Catalan Number Generator
 *
 * @author Osipov Sergei 
 * @license MIT
 */
const catalan = require('./catalan');

describe('Catalan number test', function() {
  it('Catalan number for correct data', function() {
    expect(catalan(1)).toBe(1);
  });
  it('Catalan number for zero', function() {
    expect(catalan(0)).toBe(0);
  });
  it('Catalan number for not number', function() {
    expect(catalan('4242')).toBe(0);
  });
  it('Catalan number for negative number', function() {
    expect(catalan(-1)).toBe(0);
  });
  it('Catalan number for wrong data', function() {
    expect(catalan({})).toBe(0);
  });
});