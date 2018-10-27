const readline = require('readline');
let length = 0;
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function permutation(input, isUsed, ans, currentIndex) {
  for (let i = 0; i < input.length; i++) {
    if (!isUsed[i]) {
      isUsed[i] = true;
      ans[currentIndex] = input[i];
      if (currentIndex === length - 1) {
        console.log(ans.join(""));
      } else {
        permutation(input, isUsed, ans, currentIndex + 1);
      }
      isUsed[i] = false;
    }
  }
}
let main = rl.on('line', (answer) => {
  const input = answer.split("");
  length = input.length;
  let isUsed = new Array(length).fill(0);
  let ans = [...input];
  permutation(input, isUsed, ans, 0);
});