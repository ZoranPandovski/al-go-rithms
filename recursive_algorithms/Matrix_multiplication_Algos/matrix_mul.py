import time
import matplotlib.pyplot as plt
import numpy as np
                      
#..........Matrix Multipication with divide and conquer
def divide_conquer(m1,m2):

    if m1.shape[0] == 1 or m2.shape[0] == 1:
        return m1 * m2

    
    n=m1.shape[0]
    if n%2==1 :
        m1 = np.pad(m1, (0,1), mode='constant',constant_values=(0))
        m2= np.pad(m2, (0, 1), mode='constant',constant_values=(0))
        
    
    m = int (np.ceil(n/2))
    # first matrix
    a = m1[: m , : m]
    b = m1[: m, m:]
    c = m1[m:,  m:]
    d = m1[m:, :m]
    # second matrix
    e = m2[: m, : m]
    f = m2[: m, m:]
    g = m2[m:, m:]
    h = m2[m:, :m]
    p1=divide_conquer(a,e)
    p2=divide_conquer(b,h)
    p3=divide_conquer(a,f)
    p4=divide_conquer(b,g)
    p5=divide_conquer(d,e)
    p6=divide_conquer(c,h)
    p7=divide_conquer(d,f)
    p8=divide_conquer(c,g)
    result=np.zeros((2 * m,2 * m),dtype=np.int64)
    result[: m, : m] = p1+p2
    result[: m, m:] = p3+p4
    result[m:, : m] = p5+p6
    result[m:, m:] = p7+p8
    return result[:n,:n]

#..........Matrix Multipication with iterative approach
def iterative (mat1,mat2,mat3):
    
    for i in range (mat1.shape[0]):
        for j in range (mat2.shape[0]):
            for k in range (mat2.shape[0]):
                mat3[i][j]+=mat1[i][k]*mat2[k][j]

    return mat3

#..........Matrix Multipication with vectorized approach     
def Vectorized(mat1,mat2):
    mat=np.dot(mat1,mat2)
    return mat
#..........Matrix Multipication with Strassen Algorithm
def Strassen_algo(m1,m2):
    if m1.size == 1 or m2.size == 1:
        return m1 * m2

    n = m1.shape[0]
    if n%2==1 :
        m1 = np.pad(m1, (0, 1), mode='constant',constant_values=(0))
        m2= np.pad(m2, (0, 1), mode='constant',constant_values=(0))
    m = int(np.ceil(n/2))

    # first matrix
    a = m1[: m, : m]
    b = m1[: m, m:]
    c = m1[m:, : m]
    d = m1[m:, m:]

    # second matrix
    e = m2[: m, : m]
    f = m2[: m, m:]
    g = m2[m:, : m]
    h = m2[m:, m:]

    p1 = Strassen_algo(a, f - h)
    p2 = Strassen_algo(a + b, h)
    p3 = Strassen_algo(c + d, e)
    p4 = Strassen_algo(d, g - e)
    p5 = Strassen_algo(a + d, e + h)
    p6 = Strassen_algo(b - d, g + h)
    p7 = Strassen_algo(a - c, e + f)
    result = np.zeros((2 * m, 2 * m), dtype=np.int32)
    result[: m, : m] = p5 + p4 - p2 + p6
    result[: m, m:] = p1 + p2
    result[m:, : m] = p3 + p4
    result[m:, m:] = p1 + p5 - p3 - p7

    return result[: n, : n]
    
# Calculate the time complexities
def generate_matrix():
    X=[]
    Y1=[]
    Y2=[] 
    Y3=[]
    Y4=[]
    for i in range (1,50):
        matrix1= np.random.randint(1,5,size=(i,i),dtype=np.int64)
        matrix2= np.random.randint(1,5,size=(i,i),dtype=np.int64)
        matrix3=np.zeros([i,i],dtype=np.int64)

        time2=time.time()*1000
        matrix4=divide_conquer(matrix1,matrix2)
        Y1.append(time.time()*1000-time2)
        time3=time.time()*1000

        matrix5=iterative(matrix1,matrix2,matrix3)
        Y2.append(time.time()*1000-time3)
        time4=time.time()*1000

        matrix6=Vectorized(matrix1,matrix2)
        Y3.append(time.time()*1000-time4)
        time5=time.time()*1000

        matrix7=Strassen_algo(matrix1,matrix2)
        Y4.append(time.time()*1000-time5)
        X.append(i)
       #print(f"size {i}* {i} --",Y4,"  secs \n")
    
    return [X,Y1,Y2,Y3,Y4]

# Plot the time complexities
if __name__=='__main__':

    list=generate_matrix()
    
    plt.plot(list[0],list[2],color='green',label='iterative')
    plt.plot(list[0],list[1],color="black",label= 'divide and conquer')    
    plt.plot(list[0],list[3],color='orange' ,label='vetorized')
    plt.plot(list[0],list[4],color='red',label='Strassen')
    plt.xlabel(' size ---->')
    plt.ylabel(' time----> in secs ')
    plt.legend()
    plt.show()     
