#!/bin/sh

echo "Enter a word or phrase:"
read input

input=$(echo ${input//[[:blank:]]/})	# remove spaces
reverse_input=$(echo "$input" | rev)	# reverting string 

if [ $input == $reverse_input ]
then
	echo "It's a Palindrome"
	exit 1				# "1" represents success exit
fi

echo "Nah!"
