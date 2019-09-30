#Program to find the LCM of two numbers

#Function to find GCD
def gcd(num1, num2):
    
    if num1 == num2:
        return num1
    
    if num1 > num2:
        return gcd(num1-num2, num2)
    
    return gcd(num1, num2-num1)

#Function to find LCM
def lcm(num1, num2):
    return (num1*num2) // gcd(num1, num2)

#Driver function for testing above
def test():
    num1, num2 = 12, 4
    print('LCM of {} and {} is {}'.format(num1, num2, lcm(num1, num2)))
    

    

