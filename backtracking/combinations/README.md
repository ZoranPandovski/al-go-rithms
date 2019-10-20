# Combinations

This algorithm returns all possible sub sets of size n from a given set.
The caller may optionally decide if elements are allowed to be duplicated in the sets (with replacement).

Example:
combinations('abcd', 2, false)

should return
[ [ 'a', 'b' ],
  [ 'a', 'c' ],
  [ 'a', 'd' ],
  [ 'b', 'c' ],
  [ 'b', 'd' ],
  [ 'c', 'd' ] ]

while
combinations('abcd', 2, true)

should return
[ [ 'a', 'a' ],
  [ 'a', 'b' ],
  [ 'a', 'c' ],
  [ 'a', 'd' ],
  [ 'b', 'a' ],
  [ 'b', 'b' ],
  [ 'b', 'c' ],
  [ 'b', 'd' ],
  [ 'c', 'a' ],
  [ 'c', 'b' ],
  [ 'c', 'c' ],
  [ 'c', 'd' ],
  [ 'd', 'a' ],
  [ 'd', 'b' ],
  [ 'd', 'c' ],
  [ 'd', 'd' ] ]