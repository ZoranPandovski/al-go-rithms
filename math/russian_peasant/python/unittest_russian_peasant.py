import unittest
from russian_peasant import russian_peasant as rp

class Test(unittest.TestCase):
    
    def test_simple(self):
        self.assertEqual(rp(0,0),0)
        self.assertEqual(rp(1,1),1)
        self.assertEqual(rp(2,1),2)
        

    def test(self):
        self.assertEqual(rp(100,100),10000)
        self.assertEqual(rp(1234,345234),426018756)
        self.assertEqual(rp(1582,76565),121125830)
        self.assertEqual(rp(879,95246),83721234)


if __name__ == '__main__':
    unittest.main()