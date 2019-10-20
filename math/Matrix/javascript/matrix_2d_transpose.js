function matrix_transpose (matrix) {
  let transposed_matrix = matrix[0].map(function(col, index) {
    return matrix.map(function(row) {
      return row[index];
    })
  })
  return transposed_matrix;
}
module.exports = matrix_transpose;

/*
program in action
*/
function run_transpose() {
  let arr3x3 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
  ];

let arr2x2 = [
    [1, 2],
    [3, 4]
  ];
  console.table(arr3x3);
  console.log('is transposed to: ');
  console.table(matrix_transpose(arr3x3));
  console.table(arr2x2);
  console.log('is transposed to: ');
  console.table(matrix_transpose(arr2x2));
}

// running program only is run directly and not required as a module
if (require.main === module) {
  run_transpose();
}
