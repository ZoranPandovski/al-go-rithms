//Print integers one-to-N, but print “Fizz” if an integer is divisible by three, 
//“Buzz” if an integer is divisible by five,
//“FizzBuzz” if an integer is divisible by both three and five.
//It prints out the number if it is not divisible by both 3 and 5
//This program uses for loop and if statements


function fizzBuzz(n) {
    for (let i = 1; i <= n; i++) {
      
      let out = "";
  
      if (i % 3 === 0) 
        out += "fizz";
      if (i % 5 == 0)
        out += "Buzz";
      
      console.log(out || i);
    }
  }
