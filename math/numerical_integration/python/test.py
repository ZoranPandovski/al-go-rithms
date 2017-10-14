from numerical_integration import integrate

from math import sin, log, exp

if __name__ == "__main__":
	print (integrate(sin,  0, 1, 0.001))
	print (integrate(log,  1, 2 ,0.001))
	print (integrate(exp, -1, 1, 0.001))