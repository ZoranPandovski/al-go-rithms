#!/usr/bin/env python
# coding: utf-8

# In[4]:


#!/usr/bin/env python
# coding: utf-8

# In[23]:


# -*- coding: utf-8 -*-
"""
Created on Mon Aug 31 22:52:05 2020
@author: bruno
"""

from vpython import *
from numpy import *
import matplotlib.pyplot as plt
from drawnow import *
import time

# First parameters:
L = 0.2 # in meters
H = 0.2 # in meters
W = 0.2 #in meters

# Initial Properties:
e = 8000           #Young's Module (Pa)
E = 0               #Deformation
M = 0               #Actuator Movement
S = 0               #Stress

# Parameters for actuator movement:
I = H           #Initial position
Ly = I          #Y-axis displacement.

# Defining the material (block).
bloco = box(pos = vector(0, 0, 0), size = vector(L, H, W), color = color.red);

# Defining the actuator that will compress the material.
atuador = cylinder(pos=vector(0, 0.1 ,0), axis=vector(0,5,0), radius=0.20, size = vector(L, 0.01, W), color = color.blue)

# Text boxes.
forceL=label(pos = vec(0,0.6,0), text = 'E = %1.1f N' %(e))
tensaoL=label(pos = vec(0.7,0.6,0), text = 'Strain = %1.1f ' %(0))
deformaL=label(pos = vec(-0.7,0.6,0), text = 'Displ. = %1.1f ' %(E))

#Defining the support platform for our block.
ground = box(pos = vector(0, -(H/2) , 0), size = vector(2, 0.01, 1), color = color.white)

# arrow indicating strength
pointer = arrow(pos=vector(0.5, -0.4 ,0),  axis = vector(0, -0.5, 0), shaftwidth = 0, color = color.red)

# Arrays for the graph
Stress = []
Strain = []

# Matlib Graphics
plt.ion() 
def makeFig():
    plt.plot(Strain, Stress, 'D-')       #plotar força por posição do bloco
    plt.xlabel('Strain')
    plt.ylabel('Stress')
    plt.title('Stress/Strain Plot')


#Compression Movement:
for cont in range(0, 18):
    # increase in strength
    M = M + 0.005    #Movement of 0.0005.
    
    # Updated parameters:
    Ly = Ly + 0.005               #Total Y shift = 0.009
    E = (I-Ly)/I                  #Deformation
    S = E*e                        #Stress(Tensão)
    
    # Actuator Movement:
    atuador.pos = vector(0, 0.1 - M,0)
    
    # Block Compression:
    bloco.size = vector(L + M, (H - M), W + 2*(M))   #Compressão em (X, Y, Z) de acordo com Coef. Poiss.
    bloco.pos = vector(0,-M/2 ,0)
    
    # Arrow Position:
    pointer.pos = vector(0.5, 0.1 - M ,0)
    
    # Updating other parameters
    pointer.pos = vector(0.5, 0.5 - M ,0)
    forceL.text = 'E = %1.0f N' %(e)
    tensaoL.text = 'Tensao = %1.0f N ' %(S*-1)      #Its value must be presented in module.
    deformaL.text = 'Deform. = %1.2f ' %(E*-1)      #Its value must be presented in module.
    
    # Updating vectors to the graphic shown in real time
    Stress.append(S*-1) 
    Strain.append(E*-1)
    drawnow(makeFig)  
    
    #Represent the movement slowly
    time.sleep(0.005)
