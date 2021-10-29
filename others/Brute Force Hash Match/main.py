import datetime
from hashlib import sha256

diff=int(input("Set difficulty (in range 0-100) : \nRemeber : It may take forever if you pick a big number here\n\n"))
diff=int((diff*100)/64)
print("Will look for",diff,"zeroes")
input()
x=0
chash=-1
a = datetime.datetime.now()
while chash==-1:
	print("Trying for",x)
	if sha256(str(x).encode()).hexdigest()[:diff]==('0'*diff):
		chash=sha256(str(x).encode()).hexdigest()
		b = datetime.datetime.now()
	else:
		x=x+1
print("==========")
print("Match found.",x,"in",b-a,"\n",chash)
