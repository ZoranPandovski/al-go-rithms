/*
Count subsets with given sum
*/

// recursive solution
const solve = (arr, sum, idx) => {
  if (sum === 0) {
    return 1;
  }
  if (arr.length === 0 || idx >= arr.length) {
    return 0;
  }

  let sum1 = 0;
  if (arr[idx] <= sum) {
    sum1 = solve(arr, sum - arr[idx], idx + 1);
  }
  let sum2 = solve(arr, sum, idx + 1);
  return sum1 + sum2;
};

const countSubsetsRec = (arr, sum) => {
  return solve(arr, sum, 0);
};

// bottom up dp

const countSubsets = (arr, sum) => {
  const dp = new Array(arr.length)
    .fill(1)
    .map(() => new Array(sum + 1).fill(1));

  for (let s = 1; s <= sum; s++) {
    dp[0][s] = s === arr[0] ? 1 : 0;
  }

  for (let i = 1; i < arr.length; i++) {
    for (let s = 1; s <= sum; s++) {
      dp[i][s] =
        s >= arr[i] ? dp[i - 1][s] + dp[i - 1][s - arr[i]] : dp[i - 1][s];
    }
  }
  return dp[arr.length - 1][sum];
};
