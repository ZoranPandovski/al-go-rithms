function* permutations(iterable) {
  const array = [...iterable];
  if (array.length <= 1) return yield array;
  for (const [item, index] of enumerate(array)) {
    const withoutCurrent = array.filter((_, i) => i !== index);
    for (const permutation of permutations(withoutCurrent)) {
      yield [item, ...permutation];
    }
  }
}

function* enumerate(iterable) {
  let index = 0;
  for (const item of iterable) {
    yield [item, index];
    index++;
  }
}

// Examples
const a = [...permutations('abc')];
console.log(a);

// Prints
/**
 * [
 *   [ 'a', 'b', 'c' ],
 *   [ 'a', 'c', 'b' ],
 *   [ 'b', 'a', 'c' ],
 *   [ 'b', 'c', 'a' ],
 *   [ 'c', 'a', 'b' ],
 *   [ 'c', 'b', 'a' ]
 * ]
 */
