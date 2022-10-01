from pandas import read_csv
from pandas.plotting import scatter_matrix
from matplotlib import pyplot
from sklearn.model_selection import train_test_split
from sklearn.model_selection import cross_val_score
from sklearn.model_selection import StratifiedKFold
from sklearn.metrics import classification_report
from sklearn.metrics import confusion_matrix
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.tree import DecisionTreeClassifier 
from sklearn.neighbors import KNeighborsClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.svm import SVC
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
import scipy.sparse.linalg
from scipy.sparse import linalg
url = "https://raw.githubusercontent.com/jbrownlee/Datasets/master/iris.csv"
names = ['sepal-length', 'sepal-width',
          'petal-length', 'petal-width',
          'class']
dataset = read_csv(url, names = names)


print(dataset.shape) # shape
print(dataset.head(25)) #head
print(dataset.describe()) #describe mean,min,max
print(dataset.groupby('class').size()) #no of rows


dataset.plot(kind = "box", subplots = True,
             layout = (2,2), sharex = False,
             sharey = False)
pyplot.show() #box and whisker plots

#histograms
dataset.hist()
pyplot.show() 

#scatter plot matrix
scatter_matrix(dataset)
pyplot.show()


#split out validation dataset
array = dataset.values
X = array[:,0:4]
y = array[:,4]
X_train, X_validation, Y_train,Y_validation = train_test_split(X, y, test_size=0.20, random_state = 1)

 #Checking algorithms
models = []
models.append(("LR", LogisticRegression(solver="liblinear",multi_class="ovr"))) #Logistics Regression
models.append(('LDA', LinearDiscriminantAnalysis()))    #Linear Discriminant Analysis
models.append(("KNN", KNeighborsClassifier()))          #K-Nearest Neighbors 
models.append(("CART", DecisionTreeClassifier()))       #Classification and Regression Trees
models.append(("NB", GaussianNB()))                     #Gaussian Naive Bayes 
models.append(("SVM", SVC(gamma="auto")))               #Support Vector Machines 


#examing each model turn by turn
results = []
names = []
for name, model in models:
    kfold = StratifiedKFold(n_splits=10, random_state=1, shuffle=True)
    cv_results = cross_val_score(model, X_train, Y_train, cv=kfold, scoring = "accuracy")
    results.append(cv_results)
    names.append(name)
    print("%s: %f (%f)"%(name, cv_results.mean(),cv_results.std()))
    
#Comparing ALGORITHMS
pyplot.boxplot(results, labels=names)
pyplot.title('Algorithm Comparison')
pyplot.show()
    

#Predictiion on the validation dataset
model = SVC(gamma = "auto")
model.fit(X_train, Y_train)
prediction = model.predict(X_validation)


# Evaluate predictions
print(accuracy_score(Y_validation, prediction))
print(confusion_matrix(Y_validation, prediction))
print(classification_report(Y_validation, prediction))
