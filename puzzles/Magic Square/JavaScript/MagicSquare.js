const assert = require('assert')

function createSquare(size){
   // In a magic square, every row, column, and diagonal add up to the same number.

   // The size must be odd
   if(size % 2 === 0) {
     console.log('Size must be odd')
     return false
   }

   // Initialize with zeros
   const magicSquare = new Array(size).fill(0).map(e => new Array(size).fill(0))

   let n = 1
   let i = 0
   let j = Math.floor(size/2)

   while(n <= size**2) {
     magicSquare[i][j] = n
     n += 1
     const newi = (((i - 1) % size) + size) % size
     const newj = (j + 1) % size

     if(magicSquare[newi] && magicSquare[newi][newj]) i += 1
     else {
       i = newi
       j = newj
     }
   }

   console.log(magicSquare)
   return true
}

function runTests() {
 // Test cases
 assert(createSquare(3) === true)
 assert(createSquare(5) === true)
 assert(createSquare(6) === false)
 assert(createSquare(4) === false)
}

runTests()
