## Understanding the Algorithms to implement Matrix Multiplication.

  1. Vectorized Approach
  2. Iterative Approach
  3. Divide and Conquer
  4. Strassen Multiplication

### Vectorized Approach 
```
mat=np.dot(mat1,mat2)
```
### Iterative Approach 
```
mat3[i][j]+= mat1[i][k]*mat2[k][j]
// Use 3 loops 
// Time Complexity O(n^3)
```
### Divide and Conquer 
```
p1=divide_conquer(a,e)
p2=divide_conquer(b,h)
p3=divide_conquer(a,f)
p4=divide_conquer(b,g)
p5=divide_conquer(d,e)
p6=divide_conquer(c,h)
p7=divide_conquer(d,f)
p8=divide_conquer(c,g)
result=np.zeros((2 * m,2 * m),dtype=np.int64)
result[: m, : m] = p1+p2
result[: m, m:] = p3+p4
result[m:, : m] = p5+p6
result[m:, m:] = p7+p8
return result[:n,:n]
// Recursively Calculate p1 , p2 , p3 , p4
// T(N) = 8T(N/2) + O(N2)
```
### Strassen's Method 
```
p1 = Strassen_algo(a, f - h)
p2 = Strassen_algo(a + b, h)
p3 = Strassen_algo(c + d, e)
p4 = Strassen_algo(d, g - e)
p5 = Strassen_algo(a + d, e + h)
p6 = Strassen_algo(b - d, g + h)
p7 = Strassen_algo(a - c, e + f)
result = np.zeros((2 * m, 2 * m), dtype=np.int32)
result[: m, : m] = p5 + p4 - p2 + p6
result[: m, m:] = p1 + p2
result[m:, : m] = p3 + p4
result[m:, m:] = p1 + p5 - p3 - p7
// T(N) = 7T(N/2) +  O(N2)
```
### Time Complexities 
  1. Iterative and Divide and Conquer : $O(n^3)$
  2. Strassen's Multiplication :  $O(n^(2.807)$

## Plotting Time Complexities 
![plotting](https://user-images.githubusercontent.com/73426684/193795978-15ac1730-7c65-4661-9548-91b4df8ce7c5.jpg)

Credits : [geeks for geeks](https://www.geeksforgeeks.org/strassens-matrix-multiplication/)
