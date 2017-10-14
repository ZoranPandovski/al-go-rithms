function euclidsGcd(a, b) {
  if (!a) {
    return b;
  }

  return euclidsGcd(b % a, a);
}

// test
[[ 1, 10, 1 ], [ 2, 4, 2 ], [ 2, 9, 1 ], [ 37, 91, 1 ], [ 5, 10, 5 ],
 [ 6, 9, 3 ]]
    .forEach(row => { console.assert(euclidsGcd(row[0], row[1]), row[2]); });
