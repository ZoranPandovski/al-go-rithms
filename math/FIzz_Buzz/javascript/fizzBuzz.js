// HI, My name is Adediwura Boluwatife


// This is a short program that prints each number from 1 to 100 on a new line 
//For each multiple of 3, print "Fizz" instead of the number 
//For each multiple of 5, print "Ghost" instead of the number 
//For numbers which are multiples of both 3 and 5, print "FIzzbuzz" instead of the number.

// Solution using a function,for loop and if statement

function fizzBuzz2(n) {
    for (let i = 1; i <= n; i++) {
      let str = "";
  
      if (i % 3 == 0) str += "fizz"
      if (i % 5 == 0) str += "buzz"
      if (i % 5 && i % 5 == 0) str += "fizzbuzz"
      if (str == "") str = i;
    
      console.log(str);
    }
  }