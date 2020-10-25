/**
 * Sorts an array using odd even sort.
 * @param {Array} array The array to sort.
 * @param {function} compare The compare function.
 * @param {function} swap A function to call when the swap operation is
 * performed. This can be used to listen in on internals of the algorithm.
 * @returns The sorted array.
 */
function sort(array, compare, swap) {
    var sorted = false;
    while (!sorted) {
      sorted = innerSort(array, 1, compare, swap);
      sorted = innerSort(array, 0, compare, swap) && sorted;
    }
    return array;
  }
  
  /**
   * Compares every second element of an array with its following element and
   * swaps it if not in order using a compare function.
   * @param {Array} array The array to sort.
   * @param {number} i The index to start at, should be either 0 or 1.
   * @param {function} compare The compare function.
   * @param {function} swap A function to call when the swap operation is
   * performed. This can be used to listen in on internals of the algorithm.
   * @returns The sorted array.
   */
  function innerSort(array, i, compare, swap) {
    var sorted = true;
    for (; i < array.length - 1; i += 2) {
      if (compare(array, i, i + 1) > 0) {
        swap(array, i, i + 1);
        sorted = false;
      }
    }
    return sorted;
  }

  