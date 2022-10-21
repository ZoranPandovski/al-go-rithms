#!/bin/bash

#Write a shell script to print the reverse of an input number.

echo -n "Enter the number : "
read number
reverse_number=0
while [ $number -gt 0 ]; do
	reverse_number=$((reverse_number*10 + number%10))
	number=$((number/10))
done
echo "Reverse of the number is $reverse_number"