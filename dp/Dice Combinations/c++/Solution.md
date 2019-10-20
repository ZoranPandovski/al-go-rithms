### Problem: [Dice Combinations](https://cses.fi/problemset/task/1633)
### Topic: Dynamic Programming


__Problem Statement:__ Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and 6.

To arrive at the step N, our previous one was N-1, N-2 or N-3....N-6, because we can only only get  1, 2 ... 6 from the dice.
So, the number of ways we can get to N, is equal to the sum of ways we can go to N-1, N-2 to N-6 .

```
T(n):
  if(n==0||n==1) return 1;
  if(n<0) return 0;

  return T(n-1) + T(n-2) + T(n-3) + T(n-4) + T(n-5) + T(n-6)
```

The above solution has a time complexity of Θ(n*6)!!! So it can be compiled before 1 sec.
