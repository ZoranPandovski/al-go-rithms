#!/usr/bin/env python
# coding: utf-8

# # Implementation of Gradient Descent Algorithm from scratch

# In[18]:


#Importing all the required libraries
import pandas as pd
import matplotlib.pyplot as plt
import pylab
import seaborn as sns
import numpy as np
import random
from scipy import stats


# In[22]:


#Computing cost function
def cost_function(m,theta0,theta1,x,y):
    return 1/2/m* sum([(theta0 + theta1*np.asarray([x[i]])-y[i])**2 for i in range(m)])      # Here m is the number of training exaples, theta0 and theta1 are the parameters
                                                                                                # theta0+theta1*X is our hypotheses function 
    
#Gradient Descent Algorithm function
def gradient_descent(alpha,x,y,precion_rate=0.0001,max_iterations=1000):
    converged=False
    iterations=0
    m=x.shape[0]         #number of training samples
    
    #initializing theta
    theta0=0
    theta1=0
    
    #cost function J(theta) for mean squared error
    J = cost_function(m,theta0,theta1,x,y)
    print('J=',J)
    
    #Iterate loop
    num_iterations=0
    while not converged:
        # for each training we will compute the gradient (d/d_theta J(theta))
        grad0= 1.0/m*sum([(theta0 + theta1*np.asarray([x[i]])-y[i]) for i in range (m)])
        grad1= 1.0/m*sum([(theta0 + theta1*np.asarray([x[i]])-y[i])*np.asarray([x[i]]) for i in range(m)])
        
        #update the temporary parameters 
        temp0= theta0 - alpha*grad0
        temp1= theta1 - alpha*grad1
        
        #update actual parameters
        theta0=temp0
        theta1=temp1
        
        #mean squared error 
        e = cost_function(m,theta0,theta1,x,y)
        print('J=',e)
        J=e             #update error
        iterations+=1   #update iterations
        
        
        if iterations== max_iterations:
            print("Maximum iterations exceeded!")
            converged=True
        
    return theta0,theta1
    

if __name__== '__main__':
    df=pd.read_csv('file1.txt',names=['x','y'])                           #the file has been added to the repository
    x=df['x']
    y=df['y']
    
    alpha=0.01  #learning rate
    precision_rate=0.01     #convergence criteria 
    
    #call gradient descent, and get the values for intercept(=theta0) and slope(=theta1) according to the equation y=m*x+c
    theta0,theta1= gradient_descent(alpha,x,y,precision_rate,max_iterations=1000)
    print('theta0='+str(theta0)+ 'theta1='+str(theta1))
    
    #plot to evaluate perfromance
    for i in range (x.shape[0]):
        y_predict=theta0+theta1*x
    
    pylab.plot(x,y,'o')
    pylab.plot(x,y_predict,'k-')
    pylab.show()

