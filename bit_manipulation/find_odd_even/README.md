# Find if a number is odd or even using bit manipulation

- Bitwise AND of a number with 1 results in 1, if the number is odd
- Bitwise AND of a number with 1 results in 0, if the number is even
- The bitwise AND operator is & in most programming languages

## Example:
### Input number: 5
```
5 represented as a byte   : 00000101
1 repreesnted as a byte   : 00000001 
After bitwise AND, we get : 00000001
```
So the number is odd 

### Input number: 62
```
62 represented as a byte  : 00111110
1 repreesnted as a byte   : 00000001 
After bitwise AND, we get : 00000000
```
So the number is even

