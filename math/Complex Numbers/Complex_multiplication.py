#python program to multiply two complex numbers

def multiplyComplex(z1,z2): 
    real=z1.real*z2.real-z1.imag*z2.imag
    imaginary=z1.real*z2.imag+z1.imag*z2.real
    return complex(real,imaginary)
z1 = complex(1,2)
z2 = complex(2,4) 
print(multiplyComplex(z1,z2))