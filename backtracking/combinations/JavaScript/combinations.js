function* combinations(iterable, n, withReplacement = false) {
  const array = [...iterable];
  if (n === 1) {
    yield* array.map(i => [i]);
    return;
  }
  for (const [item, index] of enumerate(array)) {
    const withoutCurrent = withReplacement ? array : array.slice(index + 1);
    for (const combination of combinations(withoutCurrent, n - 1, withReplacement)) {
      yield [item, ...combination];
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

// Example
const a = [...combinations('abcd', 2)];
console.log(a);
/**
 * [ [ 'a', 'b' ],
 *   [ 'a', 'c' ],
 *   [ 'a', 'd' ],
 *   [ 'b', 'c' ],
 *   [ 'b', 'd' ],
 *   [ 'c', 'd' ] ]
 */

const b = [...combinations('abcd', 2, true)];
console.log(b);
/**
 * [ [ 'a', 'a' ],
 *   [ 'a', 'b' ],
 *   [ 'a', 'c' ],
 *   [ 'a', 'd' ],
 *   [ 'b', 'a' ],
 *   [ 'b', 'b' ],
 *   [ 'b', 'c' ],
 *   [ 'b', 'd' ],
 *   [ 'c', 'a' ],
 *   [ 'c', 'b' ],
 *   [ 'c', 'c' ],
 *   [ 'c', 'd' ],
 *   [ 'd', 'a' ],
 *   [ 'd', 'b' ],
 *   [ 'd', 'c' ],
 *   [ 'd', 'd' ] ]
 */
