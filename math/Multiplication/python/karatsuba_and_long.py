def main():
    N = int(input())
    A = list(map(float, input().split()))
    B = list(map(float, input().split()))
    
    C = multiply(A, B)
    for c in C:
        if c==0.0: continue
        print('%.10f' % c, end=' ')
    print()
    
    
def multiply(A, B):
    return karatsuba(A,B)
    
def long(A,B):
    result = [0]*len(A)
    for i,element in enumerate(B):
        intermediate = [element*x for x in A]
        intermediate = [0]*i + intermediate
        result = [x+y for x,y in zip(result,intermediate)]
        result.append(0)
    return result
    
def karatsuba(A,B):
    N = len(A)
    if  N%2 != 0:
        A.append(.0)
        B.append(.0)
        N += 1
    
    #if N == 2:
    #    C0 = [A[0] * B[0]]
    #    C2 = [A[1] * B[1]]
    #    intermediate = [(A[0] + A[1]) * (B[0] + B[1])]
    #    C1 = [intermediate[0] - C0[0] - C2[0]]
    if N <= 100:
        return long(A,B)
    else:
        slicer = N//2
        A0,A1 = A[:slicer],A[slicer:]
        B0,B1 = B[:slicer],B[slicer:]
        C0 = karatsuba(A0[:],B0[:])
        C2 = karatsuba(A1[:],B1[:])
        A_sum = [x+y for x,y in zip(A0,A1)]
        B_sum = [x+y for x,y in zip(B0,B1)]
        intermediate = karatsuba(A_sum,B_sum)
        C1 = [x-y-z for x,y,z in zip(intermediate,C0,C2)]
    C0.extend([0]*(N))
    C1 = [0]*(N//2) + C1
    C1.extend([0]*(N//2))
    C2 = [0]*(N) + C2
    result = [x+y+z for x,y,z in zip(C0,C1,C2)]
    return result

if __name__ == '__main__':
    main()
