'''
This code file contains all the functions for implementation of gradient 
descent on a custom function. The comments and docstrings explain the code,
but for a more detailed explanation, please go through the Readme.md file
in this folder. 

'''

import numpy as np
import matplotlib.pyplot as plt
import time
import math

def func(x):
  '''
    We want to model our dataset on the sine function as it has some amount
    of complexity.
  '''
  return np.sin(x)

def create_dataset(n):
  x = np.linspace(0,10,num=n)
  # instead of using the sine function on its own, we are adding noise randomly
  y = func(x)+np.random.randn(n)*0.1
  return x,y

def show_dataset(x,y):
    # This function just displays the dataset
    a = np.linspace(0,10,num=70)
    plt.plot(a,np.sin(a),color='green')
    plt.scatter(x,y)
    plt.show()


def gradient(f,w,x,y,h,val):
  # This function is used to calculate gradients of the loss function for a certain weight.
  b,yhat = f(y,x,w)
  w[val]+=h
  a,yhat = f(y,x,w)
  g = (a-b)/h
  return g,yhat
  

def predict(x,w):
    #This function is useful for predicting results.
  x_v = [x**i for i in range(len(w))]
  return np.dot(x_v,w)


def loss(y,x,w):
  # We would be using Mean squared error as the loss function
  yhat = [predict(x,w) for x in x]
  l = sum((y-yhat)**2) / len(w)
  return l,yhat

def model_creation(lossfn,x,y,w,learning_rate,epoch):
  # This is a generic function for creating the model
  t=time.time()
  loss2=[]
  print(lossfn(y,x,w))
  yhat=[]
  grads=[0,0,0,0]
  for i in range(epoch):
    #print(grads)
    j=0
    while(j<4):
      grads[j],yhat = gradient(lossfn,w,x,y,0.0000000001,j) #calculating gradients
      j+=1
    j=0
    #print(grads)
    while(j<4):
      w[j]-= learning_rate*grads[j]  #updating weights
      j+=1
    l,_= lossfn(y,x,w)
    loss2.append(l)
    if i%1000 == 0:
      print("Loss at epoch {} is {}".format(i,l)) #prints loss for every 1000 epochs
  print("Loss at epoch {} is {}".format(epoch,l))
  return loss2,yhat

def show_output(x,y,yhat):
    a = np.linspace(0,10,num=70)
    plt.plot(a,np.sin(a),color='green')
    plt.scatter(x,y,color='black')
    plt.scatter(x,yhat,color='red')
    plt.plot(x,yhat)
    plt.show()

if __name__ == '__main__':
    # Here is the driver code
    w_vector = np.random.randn(4)
    # We will be fitting a 3 degree polynomial
    x,y = create_dataset(30)
    # The above line creates the dataset and the line below displays it.
    show_dataset(x,y)
    # The model is trained
    l,yhat = model_creation(loss,x,y,w_vector,1e-7,50000)
    #The results are shown
    show_output(x,y,yhat)
