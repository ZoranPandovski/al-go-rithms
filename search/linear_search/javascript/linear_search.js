function linearSearch(array, value) {
  return array.indexOf(value);
}

// test
[
  [ [1, 2, 3, 4], 2, 1],
  [ [1, 2, 3, 4], 4, 3],
  [ [1, 2, 3, 4], 5, -1],
  [ [1, 3, 4, 5, 6], 2, -1 ]
].forEach(test => {
  console.assert(linearSearch(test[0], test[1]) == test[2]);
});
