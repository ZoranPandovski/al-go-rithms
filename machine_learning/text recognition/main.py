import scipy.io as sio
import numpy as np
from PIL import Image
import matplotlib.pyplot as plt
import time
from random import randint

def sigmoid(s):
	return 1/(1+np.exp(-s))

data_matrix=sio.loadmat('data.mat')
theta_matrix=sio.loadmat('weights.mat')
data=sio.whosmat('data.mat')
theta=sio.whosmat('weights.mat')

input_layer=data[0][1][1]
hidden_layer=theta[0][1][0]
output_layer=theta[1][1][0]

X=data_matrix.get("X")
Y=data_matrix.get("y")
theta1=theta_matrix.get("Theta1")
theta2=theta_matrix.get("Theta2")

def predict(theta1,theta2,X):
	X=np.resize(X,(1,400))
	ones=np.ones((1,1))
	X=np.hstack((ones,X))
	#np.savetxt('X.txt',X)
	r1=X.dot(theta1.transpose())
	r1=sigmoid(r1)

	r1=np.hstack((ones,r1))
	r2=r1.dot(theta2.transpose())
	r2=sigmoid(r2)
	print(r2)

	#t=np.amax(r2,axis=1)
	t=np.argmax(r2,axis=1)
	return t

for i in range(30):
	check=randint(0,np.shape(X)[0])
	ti=predict(theta1,theta2,X[check])
	print(ti+1)
	d=np.resize(X[check][0:402],(20,20))
	plt.matshow(d, cmap=plt.get_cmap('gray'))
	plt.show()
	time.sleep(1)

#d=np.resize(X[0][2:402],(20,20))
#plt.matshow(d, cmap=plt.get_cmap('gray'))
#plt.show()
#np.savetxt('result.txt',t)
