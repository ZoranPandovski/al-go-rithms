import sys

class Lhash():
	def __init__(self):
		self.bucks = {}
		self.idx_hash = -1
		self.blocks = -1
		self.keys = -1
		self.split_idx = -1
		self.init()
	
	def init(self):
		self.idx_hash = 1
		self.bucks[0] = [[] for i in range(1)]
		self.blocks = 2
		self.keys = 0
		self.bucks[1] = [[] for i in range(1)]
		self.split_idx = 0

	def add(self):
		self.bucks[len(self.bucks)] = [[] for i in range(1)]
		self.blocks += 1
		to_up = list()
		if self.blocks == (1<<(self.idx_hash+1) + 1):
			self.split_idx = 0
			self.idx_hash += 1
	
		rem_idx = 1<<self.idx_hash

		upd_idx = len(self.bucks) - 1 - rem_idx
		
		temp = rem_idx
		rem_idx *= 0.5
		temp += rem_idx
		for _, key in enumerate(self.bucks[upd_idx]):
			for val in key:
				to_up.append(val)
			self.blocks -= 1
		
		self.bucks[upd_idx] = [ [] for i in range(1)]
		self.blocks += 1
		self.split_idx += 1

		for _, val in enumerate(to_up):

			hsh_val = self.hsh(val, self.idx_hash)
			
			if hsh_val >= self.split_idx:
				continue
			elif hsh_val < self.split_idx:
				hsh_val = self.hsh(val, self.idx_hash+1)
				self.check_size(len(self.bucks[hsh_val][-1]), hsh_val)
				self.bucks[hsh_val][-1].append(val)
			else:
				pass

	def insert(self, val):
		hash_val = val % (1<<self.idx_hash)

		if hash_val < self.split_idx:
			hash_val = val % (1<<(self.idx_hash+1))
		
		for i in self.bucks[hash_val]:
			if val in i:
				return 
		print(val)
		self.keys+=1
		self.check_size(len(self.bucks[hash_val][-1]), hash_val)
		self.bucks[hash_val][-1].append(val)
		doweneedit = self.calc()
		if doweneedit == "YES":
			self.add()
			return "Bucket added!!! You are adding a lot of data mate."
		else:
			return "Enjoy everything done"
	
	def calc(self):
		num = self.keys*4
		den = 1000
		den*= self.blocks
		com = 0.75
		if (num*1.0)/(den*1.0) > com:
			return "YES"
		else:
			return "NO"
	def hsh(self,val1,val2):
		a = 1 << val2
		b = val1
		return b % a

	def check_size(self, val, hsh):
		a = 4*val
		b = 1000
		b -= 4
		if a > b:
			self.blocks += 1
			self.bucks[hsh].append(list())
		return "done"
# Globals
output =  []
# parser command
def doit(fname):
	with open(fname,'r') as f:
		for line in f:
			cmd = line.strip().lower().split()
			hashdt.insert(int(cmd[0]))
# beginning of code
if len(sys.argv) != 2:
	sys.exit("syntax error//")
hashdt = Lhash()
fname = sys.argv[1]
doit(fname)