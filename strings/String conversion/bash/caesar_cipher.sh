#!/bin/bash

caesar_cipher_help="
The caesar_cipher function accept two parameters:
  1. The text to encript.
  2. The number of chars to totate.
"

function ord() {
  printf %d "'$1"
}

function caesar_cipher() {
  text="$1"
  rotate=$2
  length=$((122-97+1)) # ord(z) - ord(a) + 1
  test -z "$1" && echo $caesar_cipher_help && return 1
  test -z "$2" && echo $caesar_cipher_help && return 1
  echo "$text" | while read -n 1 c; do
    inc=0
    echo $c | grep -q '[A-Z]' && inc=65
    echo $c | grep -q '[a-z]' && inc=97
    if [ $inc = 0 ]; then
      test -z "$c" && echo -n ' ' || echo -n "$c"
    else
      n=$(( $inc + ( ( $(ord $c) - $inc + $rotate ) % $length ) ))
      echo -ne "\x$(printf %x $n)"
    fi
  done
  echo
}
