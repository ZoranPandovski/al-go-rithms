#!/bin/bash

check=$1
if [ -z $check ]; then
    echo "Enter a string : "
    read check
fi
 
if [ "$(echo $check | rev)" = "$check" ]
  then
    echo "\"$check\" IS a Palindrome"
  else
    echo "\"$check\" IS NOT a Palindrome"
fi