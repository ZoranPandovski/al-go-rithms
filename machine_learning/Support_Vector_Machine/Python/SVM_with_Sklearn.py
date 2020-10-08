# some imports 

from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn import svm
from sklearn import metrics

# read the dataset from sklearn dataset
cancer = datasets.load_breast_cancer()

# See the features and label names of the dataset
print("Features are: ", cancer.feature_names)
print("Labels are: ", cancer.target_names)

# Assign the values to X as featrues and to y the labels
X = cancer.data
y = cancer.target

# Split the dataset into 80% and 20% for training and testing respectively
x_train, x_test, y_train, y_test = train_test_split(X, y, test_size=0.2)

# print(x_train, y_train)

# these are the two classes of the label
classes = ['malignant', 'benign']

# Support Vector Classifier of Support Vector Machine
# Here the C is the Soft Margin for the SVM

clf = svm.SVC(kernel="linear", C=2)
clf.fit(x_train, y_train)

# predict the values of training features
y_pred = clf.predict(x_test)

# seeing the acuuracy score of the model
acc = metrics.accuracy_score(y_test, y_pred)

print("Accuracy of SVC: ", acc)

