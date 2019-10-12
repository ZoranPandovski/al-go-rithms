#python3
#program to calculate roots of a polynomial with error of .0001 

def f(x):
	return x*x - x - 1
	
print("Enter values of a and b on separate line ")
a = float(input())
b = float(input())
e = .0001

m = (a*f(b)-b*f(a))/(f(b)-f(a))
i=1
print (a,b,m,f(m),i)
while abs(f(m))>e :
			
			
				
			m = (b*f(m)-m*f(b))/(f(m)-f(b))
			i= i+1
			print (a,b,m,f(m),i)
print ("Root of polynomial :",m)
