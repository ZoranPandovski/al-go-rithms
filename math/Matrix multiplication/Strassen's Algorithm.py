def iterative_matrix_multiplication(matrix_1,matrix_2): #Iterative Multiplication O(n^3)
	"""
	input: (matrix_1, matrix_2) of dimensions lxm and mxn respectively
	output (matrix) of dimensions lxn, the product of the two input matrices
	"""
	product=[[0 for c in range (len(matrix_2[0]))]for r in range(len(matrix_1))]
	for i in range (len(matrix_1)):
		for j in range (len(matrix_2[0])):
			for k in range(len(matrix_2)):
				product[i][j]+=matrix_1[i][k]*matrix_2[k][j]
	return product

	################################################################################################

def r_m_m(matrix_1,matrix_2): #Recursive Matrix Multiplication O(n^log7)
	"""
	input: (matrix_1, matrix_2) of dimensions lxm and mxn respectively -and in case of using Strassen's optimization, nxn and nxn respectively where n is a power of two-.
	output (matrix) of dimensions lxn -and in case of Strassen's optimization, nxn- the product of the two input matrices.
	"""
	#Finding the number of rows and coloumns of each matrix
	rows_1,rows_2,columns_1,columns_2=len(matrix_1),len(matrix_2),0,0
	if matrix_1:
		columns_1=len(matrix_1[0])
	if matrix_2:
		columns_2=len(matrix_2[0])

	#Dividing each matrix into four sub-matrices
	#Set the value the sub=matrix to [] in case of [[]]
	A=[matrix_1[r][:columns_1//2] for r in range(rows_1//2)]
	if len(A)==1 and len(A[0])==0:
	    A=[]
	B=[matrix_1[r][columns_1//2:] for r in range(rows_1//2)]
	if len(B)==1 and len(B[0])==0:
	    B=[]
	C=[matrix_1[r][:columns_1//2] for r in range(rows_1//2,rows_1)]
	if len(C)==1 and len(C[0])==0:
	    C=[]
	D=[matrix_1[r][columns_1//2:] for r in range(rows_1//2,rows_1)]
	if len(D)==1 and len(D[0])==0: 
	    D=[]
	E=[matrix_2[r][:columns_2//2] for r in range(rows_2//2)]
	if len(E)==1 and len(E[0])==0:
	    E=[]
	F=[matrix_2[r][columns_2//2:] for r in range(rows_2//2)]
	if len(F)==1 and len(F[0])==0:
	    F=[]
	G=[matrix_2[r][:columns_2//2] for r in range(rows_2//2,rows_2)]
	if len(G)==1 and len(G[0])==0:
	    G=[]
	H=[matrix_2[r][columns_2//2:] for r in range(rows_2//2,rows_2)]
	if len(H)==1 and len(H[0])==0:
	    H=[]

	#Base Case: All sub-matrices are empty except D,H ie. the product of two 1x1 matrices
	if not (len(A) or len(B) or len(C) or len(E) or len(F) or len(G)): #De Morgan's Theorem
	    if len(D)==1 and len(H)==1:
	        return [[D[0][0]*H[0][0]]]
	    else:
	        return []

	#Regular Divide and conquer approach O(n^3)
	# I=m_a(r_m_m(A,E),r_m_m(B,G))
	# II=m_a(r_m_m(A,F),r_m_m(B,H))
	# III=m_a(r_m_m(C,E),r_m_m(D,G))
	# IV=m_a(r_m_m(C,F),r_m_m(D,H))
	# return combine(I,II,III,IV)

	#Optimized Strassen's Algorithm O(n^log7) works for SQUARE MATRICES (n x n) with n equal to 2^m only
	P1=r_m_m(A,m_s(F,H))
	P2=r_m_m(m_a(A,B),H)
	P3=r_m_m(m_a(C,D),E)
	P4=r_m_m(D,m_s(G,E))
	P5=r_m_m(m_a(A,D),m_a(E,H))
	P6=r_m_m(m_s(B,D),m_a(G,H))
	P7=r_m_m(m_s(A,C),m_a(E,F))

	I=m_a(m_a(P6,m_s(P4,P2)),P5)
	II=m_a(P1,P2)
	III=m_a(P3,P4)
	IV=m_a(P1,m_s(P5,m_a(P3,P7)))
	return combine(I,II,III,IV)


def m_a(matrix_1,matrix_2): #Matrix Addition
	"""
	A helper function for the r_m_m() function
	input: Two matrices of the same dimensions
	output: A matrix, the summation of these two matrices
	"""
	#If both lists are non-empty:
	if matrix_1 and matrix_2:
	    return [[matrix_1[i][j]+matrix_2[i][j] for j in range (len(matrix_1[0]))]for i in range (len(matrix_1))]
	#Else: One of them is empty or both are empty
	else:
	    return matrix_2 or matrix_1


def m_s(matrix_1,matrix_2): #Matrix Subtraction
	"""
	A helper function for the r_m_m() function
	input: Two matrices of the same dimensions
	output: A matrix, the subtraction of these two matrices
	"""
	if matrix_1 and matrix_2:
	    return [[matrix_1[i][j]-matrix_2[i][j] for j in range (len(matrix_1[0]))]for i in range (len(matrix_1))]
	else:
	    return matrix_2 or matrix_1


def combine(matrix_1,matrix_2,matrix_3,matrix_4): #Combine the four sub-matrices into one matrix

	#Declare combined_matrix and initialize the num of rows of combined_matrix
	combined_matrix=[]
	num_rows_combined=max(len(matrix_1),len(matrix_2))+max(len(matrix_3),len(matrix_4)) #Using max to avoid considering the empty matrix rows

	#Merge matrix_1 and matrix_2 into combined_matrix
	for i in range (num_rows_combined//2):
	    if len(matrix_1)==0:
	        temp_1=[]
	    else:
	        temp_1=matrix_1[i]
	    if len(matrix_2)==0:
	        temp_2=[]
	    else:
	        temp_2=matrix_2[i]
	    if len(temp_1+temp_2):
	        combined_matrix.append(temp_1+temp_2)

	#Merge matrix_3 and matrix_4 into combined_matrix
	for i in range (num_rows_combined//2+(num_rows_combined&1)):
	    if len(matrix_3)==0:
	        temp_1=[]
	    else:
	        temp_1=matrix_3[i]
	    if len(matrix_4)==0:
	        temp_2=[]
	    else:
	        temp_2=matrix_4[i]
	    if len(temp_1+temp_2):
	        combined_matrix.append(temp_1+temp_2)
	return combined_matrix

	################################################################################################
def main():
  matrix_1,matrix_2=[[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]],[[0,1,2,3],[4,5,6,7],[8,9,10,11],[12,13,14,15]]
  print(r_m_m(matrix_1,matrix_2))
  
if __name__=="__main__":
  main()
