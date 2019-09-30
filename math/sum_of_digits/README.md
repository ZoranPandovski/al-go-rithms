The sum of digits of n (also known as the [digit sum](https://en.wikipedia.org/wiki/Digit_sum) of n) is, well, the sum of the digits of n. 
For example, the sum of digits of the number 123 is 1 + 2 + 3 = 6.
```
def digit_sum(n):
 total = 0
 while n > 0:
  //Note that you can replace 10 with any base you want.
  total += n % 10 //n % 10 gives you the last (least significant) digit.
  n = n / 10 //Dividing by ten chops that last digit off.
 return total
```
