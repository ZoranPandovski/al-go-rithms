const ceaser = (text, shift) => text.replace(/([a-z])|([A-Z])/g, (_, lo, hi) => {
  let letter = lo ? 'a'.charCodeAt(0) : 'A'.charCodeAt(0);
  return String.fromCharCode(letter + (26 + (lo || hi).charCodeAt(0) - letter + shift % 26) % 26);
});

module.exports = ceaser;
