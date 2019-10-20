#python3
#program to calculate roots of a polynomial with error of .0001 

def polynomial(x):
	return x*x - x - 1
	
print("Enter values of a and b on separate line ")
a = float(input())
b = float(input())
e = .0001

m = (a*polynomial(b)-b*polynomial(a))/(polynomial(b)-polynomial(a))
i=1
print (a,b,m,polynomial(m),i)
while abs(polynomial(m))>e :
	m = (b*polynomial(m)-m*polynomial(b))/(polynomial(m)-polynomial(b))
	i= i+1
	print (a,b,m,polynomial(m),i)
print ("Root of polynomial :",m)
