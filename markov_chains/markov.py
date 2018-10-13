#USAGE
#python3 markov.py textFile
#generates random text using textFile
import sys
from random import choice

with open(sys.argv[1]) as f:
	text=f.read()

matrix = {}
step=2  # how long is one chain?
length=400

for i in range(step,len(text),step):
	try:
		key=text[i-step:i]
		r=text[i:i+step]
	except IndexError:
		break
	if key in matrix:
		matrix[key].append(r)
	else:
		matrix[key] = [ r ]


b=choice(list(matrix.keys()))
out=b

while len(out)<length:
	b=choice(matrix[b])
	out+=b

print(out)
