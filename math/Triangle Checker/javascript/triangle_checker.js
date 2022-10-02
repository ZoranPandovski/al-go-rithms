function isValidTriangle(a, b, c) {
  //to be a valid triangle the sum of two sides must be greater than the other side for all sides.
  if ( ((a+b) > c) && ((a+c) > b) && ((b+c) > a)){
    return true;
  }
  else {
    return false;
  }
}

//making tests

console.log(isValidTriangle(3,3,3));
//true

console.log(isValidTriangle(3,4,5));
//true

console.log(isValidTriangle(2,10,12));
//false

