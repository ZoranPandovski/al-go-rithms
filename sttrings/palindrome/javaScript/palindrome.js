// Read the user console input
const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

// Take a word from the user as input and your output is true if is palindrome word or false if not 
readline.question('Enter a word:', word => {   
  if ( isPalindrome(word) ) {
    console.log(`The word ${word} is a palidrome!`);
  } else {
    console.log(`The word ${word} is not a palidrome`);
  }
  readline.close();
});

function isPalindrome(word) {
  // Parse the word to use the 'reverse()' function and we can compare the word with its reversed version
  var splitString = word.split("");
  var splitReversedWord = splitString.reverse();
  var reversedWord = splitReversedWord.join("")

  if (word == reversedWord) {
    return true;
  } 
  return false;

}
