// Read the user console input
const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

// Take a positive number from the user as input and your output is true if is perfect square or false if in not 
readline.question('Enter a positive number:', input => {   
  let result = isSquare(input);
  // Verify if is negative number
  if ( result==-1 ) {
    console.log(`Error: The number ${input} informed is negative!`);   
  } else if ( result ) {
    console.log(`The number ${input} is an perfect square`);
  } else {
    console.log(`The number ${input} is not an perfect square`);
  }
  readline.close();
});

function isSquare(input) {
  let number = parseInt(input);
  
  if (number < 0) return -1;

  let result = Math.sqrt(number);
  if (result%1==0) {
    return true;
  } 
  return false;
}
