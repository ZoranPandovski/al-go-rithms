function euclidsGcd(a, b) {
  if (!a) {
    return b;
  }

  return euclidsGcd(b % a, a);
}

module.exports = euclidsGcd;
