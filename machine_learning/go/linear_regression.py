#!/usr/bin/env python
# coding: utf-8

# # Simple Linear Regression using Scikit-Learn

# In[2]:


import numpy as np
import pandas as pd


# In[4]:


df=pd.read_csv('housing.data',delim_whitespace=True,header=None)                 # This file 'housing.data' has been added to the repository
col_name=['CRIM','ZN','INDUS','CHAS','NOX','RM','AGE','DIS','RAD','TAX','PTRATIO','B','LSTAT','MEDV']
df.columns=col_name


# In[ ]:


import matplotlib.pyplot as plt
import seaborn as sns

#df.head()      -To view the 14 by 14 feature matrix and target matrix
X=df['LSAT'].values.reshape(-1,1)                  # We are choosing %age lower status of population as our input feature in this univariate linear regression model
y=df['MEDV'].values                                # We are choosing median values of owner-occupied homes as our target value
from sklearn.linear_model import LinearRegression   
model=LinearRegression()
model.fit(X,y)                                      # Fitting our values into linear regression model imported from scikit-learn library
plt.figure(figsize=(12,10));
sns.regplot(X,y);
plt.xlabel('%age lower status of the population')
plt.ylabel("median values of owner-occupied homes in $1000's")
plt.show();


# # Regression Model - splitting the data into training and test sets and then predicting the outcome

# In[ ]:


from sklearn.model_selection import train_test_split              # This divides our dataset into training data and test data


# In[ ]:


X=df['LSTAT'].values.reshape(-1,1)
y=df['MEDV'].values
X_train,X_test,y_train,y_test=train_test_split(X,y,test_size=0.2,random_state=0)          # Keeping 20% as test data and 80% as training data
lr=LinearRegression()
lr.fit(X_train,y_train)
y_train_pred=lr.predict(X_train)                                                          # Predicted value of traing data 
y_test_pred=lr.predict(X_test)                                                            # Predicted value of test data


# # For a near perfect model

# In[ ]:


generate_random=np.random.RandomState(0)                             # Generating random data points for best fit curve
x=10*generate_random.rand(1000)
y=3*x+np.random.randn(1000)                                         # From y=m*x+c equation 


# In[ ]:


from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(x, y, test_size=0.3, random_state=0)          # Here we are holding out 30% of data as test data since we have a lot of data points
from sklearn.linear_model import LinearRegression
model = LinearRegression(fit_intercept=True)
model.fit(X_train.reshape(-1, 1), y_train)


y_train_pred = model.predict(X_train.reshape(-1, 1))
y_test_pred = model.predict(X_test.reshape(-1, 1))

