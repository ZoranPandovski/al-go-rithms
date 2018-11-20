from week5_ex1_basic import *
import unittest

class TestMyMethods(unittest.TestCase):

	def testNoRepeated(self):
		l=List()
		l.insert(None, Node(4))
		l.insert(l.head,Node(6))
		l.insert(l.head,Node(8))
		
		self.assertEqual(l.removeRepeated().toNativeList(), [4,8,6])

	def testRepeated(self):
		l=List()
		l.insert(None, Node(4))
		l.insert(l.head,Node(6))
		l.insert(l.head,Node(8))
		l.insert(l.head,Node(6))
		
		self.assertEqual(l.removeRepeated().toNativeList(), [4,6,8])

unittest.main()