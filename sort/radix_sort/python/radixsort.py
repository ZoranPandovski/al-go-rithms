# note that this implementation only works for sequences of positive integers
class RadixSort:
    def __init__(self,a):
        self.a = a

    def result(self):
        maxElement = max(self.a)
        exp = 1
        while int(maxElement/exp) > 0:
            self.countingsort(exp)
            exp *= 10

        return self.a

    def countingsort(self,exp):
        position = [0]*(10)
        b = [0]*(len(self.a))
        for i in range(len(self.a)):
            index = int(self.a[i]/exp)
            position[index%10] += 1
        for i in range(1,10):
            position[i] += position[i-1]
        for i in range(len(self.a)-1,-1,-1):
            index = int(self.a[i]/exp)
            b[position[index%10]-1] = self.a[i]
            position[index%10] -= 1
            
        self.a = b

if __name__ == '__main__':
    from random import randint
    import unittest

    class TestRadixSort(unittest.TestCase):
        def test_random_set(self):
            num_case = 20
            min_val = 1
            max_val = 5
            min_length = 1
            max_length = 10

            check_match = lambda a, b: sum([i==j for i,j in zip(a,b)]) == len(a)
        
            for i in range(num_case):
                input_sequence = [randint(min_val,max_val) for i in range(randint(min_length,max_length))]
                radix_sorted_sequence = RadixSort(input_sequence).result()
                builtin_sorted_sequence = sorted(input_sequence)
                debug_msg = '\ninput       ' + str(input_sequence) + \
                            '\noutput      ' + str(radix_sorted_sequence) + \
                            '\ntrue output ' + str(builtin_sorted_sequence)
                
                self.assertTrue(check_match(builtin_sorted_sequence, radix_sorted_sequence), msg=debug_msg)

    unittest.main()
    
