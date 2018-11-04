function isPowerOfTwo(number) {
  return (number && !(number & (number - 1)))
} // Returns a boolean value

var userNumber = 64 // Replace 64 with your own number

if(isPowerOfTwo(userNumber)) console.log(`The number ${userNumber} is a power of TWO`)
else console.log(`The number ${userNumber} is NOT a power of TWO`)

// In your Node environment execute this file as : node power_of_two.js
