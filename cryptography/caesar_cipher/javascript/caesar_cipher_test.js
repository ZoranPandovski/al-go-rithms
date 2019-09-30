// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const caesar = require('./caesar_cipher');

describe('Caesar Cipher', () => {
  [
    [ 'Hello', 3, 'Khoor'],
    [ 'The quick brown fox jumps over the lazy dog.', 0, 'The quick brown fox jumps over the lazy dog.'],
    [ 'The quick brown fox jumps over the lazy dog.', 26, 'The quick brown fox jumps over the lazy dog.'],
    [ 'test', 3, 'whvw' ],
    [ 'whvw', -3, 'test' ],
    [ 'the quick brown fox jumps over the lazy dog', 10, 'dro aesmu lbygx pyh tewzc yfob dro vkji nyq' ],
    [ 'dro aesmu lbygx pyh tewzc yfob dro vkji nyq', -10, 'the quick brown fox jumps over the lazy dog' ],
  ].forEach(test => {
    it(`Cipher '${test[0]}' shift(${test[1]})`, () => {
      expect(caesar(test[0], test[1])).toBe(test[2]);
    })
  })
});
