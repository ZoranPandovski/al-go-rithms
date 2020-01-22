/**
 * Aho corasick algorithm.
 *
 * @param   Array   list pattern keywords
 * @param   String  words indicated contain a keywords
 * @return  void
 */
function ahoCorasick (patterns, words) {
  let indexPatterns = 0;
  let lengthPatterns = patterns.length;
  let lengthWords = words.length;

  while (typeof patterns[indexPatterns] !== 'undefined') {
    let indexPattern = 0;
    let charPattern = null;
    let lengthPattern = patterns[indexPatterns].length;
    let indexWords = 0;
    let charWord = null;

    while (words[indexWords]) {
      charWord = words[indexWords];

      if (charWord === charPattern) {
        indexPattern += 1;

        // is last character in pattern keyword ?
        if (indexPattern >= lengthPattern) {
          indexPattern = 0;

          console.log(`Pattern ${patterns[indexPatterns]} find in range [${indexWords}-${indexWords+indexPattern}]`);
        }

        charPattern = patterns[indexPatterns][indexPattern];
      } else {
        indexPattern = 0;
        charPattern = patterns[indexPatterns][indexPattern];
      }

      // go to next character
      indexWords++;

      // no have more character ?
      if (indexWords >= lengthWords) {
        break;
      }
    }

    // go to next pattern
    indexPatterns += 1;

    // no have more pattern ?
    if (indexPatterns >= lengthPatterns) {
      break;
    }
  }
}