const euclids_gcd = (a, b) => {
  if (a === 0) return b;
  return euclids_gcd(b % a, a);
};

module.exports = euclids_gcd ;