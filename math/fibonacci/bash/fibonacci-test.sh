#!/usr/bin/env shunit2

# $1 is the path for this script, as first parameter of shunit2
f="$(dirname "$1")/fibonacci.sh"

test_fibonacci_zero() {
  $f 0 2>/dev/null && fail 'Position zero does not exists' || assertEquals 1 $?
}

test_fibonacci_first() {
  assertEquals $($f 1) 1
}

test_fibonacci_second() {
  assertEquals $($f 2) 1
}

test_fibonacci_third() {
  assertEquals $($f 3) 2
}

test_fibonacci_fifth() {
  assertEquals $($f 5) 5
}

test_fibonacci_tenth() {
  assertEquals $($f 10) 55
}
