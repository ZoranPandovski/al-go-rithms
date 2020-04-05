const transpose = require('./matrix_2d_transpose');

describe('Matrix Transpose', () => {
  let arr2x2 = [
    [1, 2],
    [3, 4]
  ];
  let arr3x3 = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]
  ];

  test('test 1x1', () => {
    let transposed = transpose([[1]]);
    expect(transposed[0][0]).toBe(1);
  });

  test('test 2x2 matrix transpose', () => {
    let transposed = transpose(arr2x2);
    expect(transposed[0][0]).toBe(1);
    expect(transposed[0][1]).toBe(3);
    expect(transposed[1][0]).toBe(2);
    expect(transposed[1][1]).toBe(4);
  });

  test('test 3x3 matrix transpose', () => {
    let transposed = transpose(arr3x3);
    expect(transposed[0][0]).toBe(1);
    expect(transposed[0][1]).toBe(4);
    expect(transposed[0][2]).toBe(7);
    expect(transposed[1][0]).toBe(2);
    expect(transposed[1][1]).toBe(5);
    expect(transposed[1][2]).toBe(8);
    expect(transposed[2][0]).toBe(3);
    expect(transposed[2][1]).toBe(6);
    expect(transposed[2][2]).toBe(9);
  });
});