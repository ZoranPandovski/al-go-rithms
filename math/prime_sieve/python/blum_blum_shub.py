from create_large_primes import generateLargePrime

def generatePusedoRandom(n=10):
    """
        :author @AKS1996
        :n      length of list it ought to return
        :return Pusedo random number

        Ref: https://en.wikipedia.org/wiki/Blum_Blum_Shub
        x(n+1) = x(n)*x(n) mod M, where M = p*q, two large primes
    """
    p = generateLargePrime(10) # 10 is bit length
    q = generateLargePrime(10)

    mList = [2] # can begin from any small prime
    for i in range(n):
        mList.append(pow(mList[i],2,p*q))

    return mList


print(generatePusedoRandom())
