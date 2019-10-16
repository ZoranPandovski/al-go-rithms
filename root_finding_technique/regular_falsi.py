#python3
#program to calculate roots of a polynomial with error of .0001 

def polynomial(x):
	return x*x - x - 1
	
print("Enter values of a and b on separate line ")
a = float(input())
b = float(input())
e = .0001

if polynomial(a)*polynomial(b)>0:
	print("Invalid internal, Root does not exist in it")
else:
	m = (a*polynomial(b)-b*polynomial(a))/(polynomial(b)-f(a))
	i=1
	print (a,b,m,polynomial(m),i)
	while abs(polynomial(m))>e :
		if polynomial(a)*polynomial(m)>0:
			a = m
		else:
			b = m
		m = (a*polynomial(b)-b*polynomial(a))/(polynomial(b)-polynomial(a))
		i= i+1
		print (a,b,m,polynomial(m),polynomial(a)*polynomial(m),i)
	print ("Root of polynomial :",m)
