PRIME = 30011

def FibRepSq(n):
    if n==0:
        return 0
    magic_mat = [[1,1],[1,0]]
    f1_f0 = [[1],[0]]
    magic_mat = power(magic_mat,n-1)
    result = matmul(magic_mat,f1_f0)
    return result[0][0]

def matmul(A,B):
    result = list()
    for i in range(len(A)):
        result.append(list())
        for j in range(len(B[0])):
            column = [x[j] for x in B]
            result[i].append(dot(A[i],column))
    return result

def dot(x,y):
    result = 0
    for xi,yi in zip(x,y):
        result += xi*yi
    return result % PRIME

def square(A):
    return matmul(A,A)

def power(X,n):
    if n < 0:
        return X
    if n == 0:
        return [[1,0],[0,1]]
    if n == 1:
        return X
    if n%2 == 0:
        return square(power(X,n/2))
    if n%2 != 0:
        return matmul(square(power(X,(n-1)/2)),X)
