#!/bin/bash -e

function line_sort() {
  echo $(echo $1 | sed -r 's/(.)/\1\n/g' | sort) | sed 's/ //g'
}

function is_anagram() {
  test -z "$1" && return 1
  test -z "$2" && return 1
  s1=$( line_sort $1 )
  s2=$( line_sort $2 )
  test $s1 = $s2
  return $?
}
