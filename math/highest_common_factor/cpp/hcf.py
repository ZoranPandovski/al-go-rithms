
#A python program to determine the highest common factor of positive integers only.

def hcf(x, y):

    #set the highest common factor to 1
    
    hcf = 1
    
    #To check if one of the number is divisible by the other
    
    if x % y == 0:
        return y
    
    #iterate within half the range of one of the numbers in a descending order
    #then we assign it to hcf if it can divide both x & y without remainder
    
    for k in range(int(y / 2), 0, -1):
        if x % k == 0 and y % k == 0:
            hcf = k
            break
    
    #when there is no common factor, return 1
    
    return hcf

#save the program as hcf.py to run the unit test
#------------------------------------------------------

#To test the program

import hcf
import unittest

class TestHCFFunction(unittest.TestCase):
    def setUp(self):
        pass
    def tearDown(self):
        pass
    def testsimple(self):
        a = hcf.hcf(40,16)
        self.assertEqual(a,8)

if __name__ == '__main__':
    unittest.main()
