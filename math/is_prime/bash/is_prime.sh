#!/bin/bash -e

function is_prime() {
    test $1 -le 1 && return 1
    test $1 -le 3 && return 0
    test $(($1 % 2)) = 0 -o $(($1 % 3)) = 0 && return 1
    i=5
    while [ $((i * i)) -le $1 ]; do
      test $(($1 % i)) = 0 -o $(($1 % (i + 2))) = 0 && return 1
      i=$(( i + 6 ))
    done
    return 0
}
