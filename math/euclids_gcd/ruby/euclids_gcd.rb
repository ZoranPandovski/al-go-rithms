# Function implementing Euclid's GCD Algorithm
def euclids_gcd (a = 1, b = 1)
#########################################################################################################################
	#The Euclidean Algorithm for finding GCD(A,B) is as follows:
		# If A = 0 then GCD(A,B)=B, since the GCD(0,B)=B, and we can stop.  
		# If B = 0 then GCD(A,B)=A, since the GCD(A,0)=A, and we can stop.  
		# Write A in quotient remainder form (A = B⋅Q + R)
		# Find GCD(B,R) using the Euclidean Algorithm since GCD(A,B) = GCD(B,R)
#########################################################################################################################
	divisor = b
	dividend = a
	while (divisor != 0)
		remainder = dividend % divisor
		dividend = divisor
		divisor = remainder
	end

	gcd = dividend
	return gcd
end

# Take 2 numbers from the user as input  and output the GCD
print("Enter 2 Numbers: ")
a, b = gets.split.map(&:to_i)
gcd = euclids_gcd(a, b)
print("Greatest Common Divisor of " + a.to_s + " and " + b.to_s + " is " + gcd.to_s + "\n")
