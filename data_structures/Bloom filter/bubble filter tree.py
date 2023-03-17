#A Bloom filter is a space-efficient probabilistic data structure that is used to test whether an element is a
# member of a set. For example, checking availability of username is set membership problem, where the set is the
# list of all registered username. The price we pay for efficiency is that it is probabilistic in nature that means,
# there might be some False Positive results. False positive means, it might tell that given username is
# already taken but actually it’s not.

# Python 3 program to build Bloom Filter
# Install mmh3 and bitarray 3rd party module first
# pip install mmh3
# pip install bitarray
import math
import mmh3
from bitarray import bitarray
from random import shuffle


class BloomFilter(object):



	def __init__(self, items_count, fp_prob):

		self.fp_prob = fp_prob

		# Size of bit array to use
		self.size = self.get_size(items_count, fp_prob)

		# number of hash functions to use
		self.hash_count = self.get_hash_count(self.size, items_count)

		# Bit array of given size
		self.bit_array = bitarray(self.size)

		# initialize all bits as 0
		self.bit_array.setall(0)

	def add(self, item):

		digests = []
		for i in range(self.hash_count):

			digest = mmh3.hash(item, i) % self.size
			digests.append(digest)


			self.bit_array[digest] = True

	def check(self, item):

		for i in range(self.hash_count):
			digest = mmh3.hash(item, i) % self.size
			if self.bit_array[digest] == False:

				return False
		return True

	@classmethod
	def get_size(self, n, p):

		m = -(n * math.log(p))/(math.log(2)**2)
		return int(m)

	@classmethod
	def get_hash_count(self, m, n):

		k = (m/n) * math.log(2)
		return int(k)



n = 20 #no of items to add
p = 0.05 #false positive probability

bloomf = BloomFilter(n,p)
print("Size of bit array:{}".format(bloomf.size))
print("False positive Probability:{}".format(bloomf.fp_prob))
print("Number of hash functions:{}".format(bloomf.hash_count))

# words to be added
word_present = ['abound','abounds','abundance','abundant','accessible',
				'bloom','blossom','bolster','bonny','bonus','bonuses',
				'coherent','cohesive','colorful','comely','comfort',
				'gems','generosity','generous','generously','genial']

# word not added
word_absent = ['bluff','cheater','hate','war','humanity',
			'racism','hurt','nuke','gloomy','facebook',
			'geeksforgeeks','twitter']

for item in word_present:
	bloomf.add(item)

shuffle(word_present)
shuffle(word_absent)

test_words = word_present[:10] + word_absent
shuffle(test_words)
for word in test_words:
	if bloomf.check(word):
		if word in word_absent:
			print("'{}' is a false positive!".format(word))
		else:
			print("'{}' is probably present!".format(word))
	else:
		print("'{}' is definitely not present!".format(word))




#code contributed by Isaac
