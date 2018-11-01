#!/bin/bash -e

function remove_space() {
  echo $1 | sed -r 's/\s//g'
}

function is_palindrome() {
  test -z "$1" && return 1
  test -z "$2" && return 1
  s1=$( remove_space "$1" )
  s2=$( remove_space "$2" | rev )
  test $s1 = $s2
  return $?
}
