/**
 * Kadane's algorithm is one of the most efficient ways to
 * calculate the maximum contiguos subarray sum for a given array.
 * Below is the implementation of kadanes's algorithm along with
 * some sample test cases.
 * There might be a special case in this problem if al the elements
 * of the given array are negative. In such a case, the maximum negative
 * value present in the array is the answer.
 */

function kadaneAlgo(array) {
  let cummulativeSum = 0;
  let maxSum = Number.NEGATIVE_INFINITY; // maxSum has the least posible value
  for (let i = 0; i < array.length; i++) {
    cummulativeSum = cummulativeSum + array[i];
    if (maxSum < cummulativeSum) {
      maxSum = cummulativeSum;
    } else if (cummulativeSum < 0) {
      cummulativeSum = 0;
    }
  }
  return maxSum;
  // This function returns largest sum contiguous sum in a array
}

function main() {
  let arr = [1, 2, 3, -5, -6];
  let sum = kadaneAlgo(arr);
  console.log(sum);
}
main();
