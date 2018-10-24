def SieveOfEratosthenes(n):
    '''
    This function returns a list
    which can be used for lookup of a number
    to check whether it is prime or not

    Input: max number to be looked up
    
    '''
    prime = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True):
            for i in range(p * 2, n+1, p): 
                prime[i] = False
        p += 1

    prime[0]=False
    prime[1]=False
    return prime


if __name__ == "__main__" :
    '''example use'''
    max_val = 10
    lookup_list = SieveOfEratosthenes(max_val)
    for num in range(max_val+1):
        print(num,': ', lookup_list[num])
