const ceaser = (text, shift) => text.replace(/([a-z])|([A-Z])/g, (_, lo, hi) => {
  let letter = lo ? 'a'.charCodeAt(0) : 'A'.charCodeAt(0);
  return String.fromCharCode(letter + (26 + (lo || hi).charCodeAt(0) - letter + shift % 26) % 26);
});


// test
[
  [ 'Hello', 3, 'Khoor'],
  [ 'The quick brown fox jumps over the lazy dog.', 0, 'The quick brown fox jumps over the lazy dog.'],
  [ 'The quick brown fox jumps over the lazy dog.', 26, 'The quick brown fox jumps over the lazy dog.'],
  [ 'test', 3, 'whvw' ],
  [ 'whvw', -3, 'test' ],
  [ 'the quick brown fox jumps over the lazy dog', 10, 'dro aesmu lbygx pyh tewzc yfob dro vkji nyq' ],
  [ 'dro aesmu lbygx pyh tewzc yfob dro vkji nyq', -10, 'the quick brown fox jumps over the lazy dog' ],
].forEach(test => {
  console.assert(ceaser(test[0], test[1]) == test[2]);
})
