import unittest
import fibonacci 

class Test(unittest.TestCase):
    
    def test_simple(self):
        self.assertEqual(fibonacci.fibonacci(0),0)
        self.assertEqual(fibonacci.fibonacci(1),1)
        self.assertEqual(fibonacci.fibonacci(2),1)

    def test(self):
        self.assertEqual(fibonacci.fibonacci(5),5)
        self.assertEqual(fibonacci.fibonacci(10),55)
        self.assertEqual(fibonacci.fibonacci(20),6765)
        self.assertEqual(fibonacci.fibonacci(30),832040)
        self.assertEqual(fibonacci.fibonacci(40),102334155)


if __name__ == '__main__':
    unittest.main()