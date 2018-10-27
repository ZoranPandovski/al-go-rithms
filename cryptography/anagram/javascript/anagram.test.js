const mocha = require('mocha');
const expect = require('expect');
const {anagram} = require('./anagram');

describe('Anagrams', () => {
  it('should implement anagrams', () => {
    expect(anagram('I eat curry','yrr tu aceI')).toBeTruthy();
    expect(anagram('I eat curry','yfd tu aceI')).toBeFalsy();
    expect(anagram('I eat curry','yrr tu ageI')).toBeFalsy();
  });
});
