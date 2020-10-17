// Reverse the list from index 0 to index end-1 and return the result
const flip = (inputArray, end) => {
  const flippedSection = inputArray.slice(0, end).reverse();
  const fixedSection = inputArray.slice(end, inputArray.length);
  return flippedSection.concat(fixedSection);
};

// This implementation assumes input is list of numbers
const pancakeSort = list => {
  let numberOfFixedElements = 0;

  while (numberOfFixedElements < list.length) {
    const unfixedSublist = list.slice(0, list.length - numberOfFixedElements);
    const highestUnfixedValue = Math.max(...unfixedSublist);
    list = flip(list, list.indexOf(highestUnfixedValue) + 1);
    list = flip(list, list.length - numberOfFixedElements);
    numberOfFixedElements++;
  }
  return list;
};

module.exports = pancakeSort;
