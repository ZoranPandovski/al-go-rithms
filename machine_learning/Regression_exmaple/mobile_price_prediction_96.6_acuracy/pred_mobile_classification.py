
# coding: utf-8

# In[1]:


import pandas as pd
import numpy as np
from sklearn.linear_model import LogisticRegression
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score
from sklearn.preprocessing import StandardScaler
import csv


# In[2]:


data = pd.read_csv('train.csv')
X, y = data.iloc[:,:-1].values, data.iloc[0:,-1].values


# In[3]:


testdata =pd.read_csv('test.csv')


# In[4]:


X_test=testdata.iloc[:,1:]


# In[5]:


from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
X=sc_X.fit_transform(X)
X_test=sc_X.transform(X_test)


# In[6]:


lr = LogisticRegression(class_weight='balanced',C=1e3, solver='newton-cg', multi_class='multinomial')
lr.fit(X,y)
y_predict = lr.predict(X_test)


# In[8]:


file = open("Predictions.csv","w",newline="")
new_file = csv.writer(file)
new_file.writerow(['id','price_range'])
for i in range(0,1000):
    new_file.writerow(list([i+1,y_predict[i]]))


# In[10]:




