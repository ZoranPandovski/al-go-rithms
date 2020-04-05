## Principal Component Analysis

The main idea of principal component analysis (PCA) is to reduce the dimensionality of a data set consisting of many variables correlated with each other, either heavily or lightly, while retaining the variation present in the dataset, up to the maximum extent. 

The same is done by transforming the variables to a new set of variables, which are known as the principal components (or simply, the PCs) and are orthogonal, ordered such that the retention of variation present in the original variables decreases as we move down in the order. So, in this way, the 1st principal component retains maximum variation that was present in the original components. 

The principal components are the eigenvectors of a covariance matrix, and hence they are orthogonal.

Pricipal Component Analysis (PCA) has been implemented in MATLAB using in built function "svd" whose definition is as follows:-
	[U,S,V] = svd(X) produces a diagonal matrix S, of the same dimension as X and with nonnegative diagonal elements in decreasing order, d unitary matrices U and V so that X = U*S*V'.
	U is an n X n matrix where n denotes the number of features in training set example.
	S is a diagonal matrix of dimensions n X n that is used for determining the retention of variance before and after projection of training set examples fron n features to k features.

The pca.m depicts the algorithm of converting an n featured training example to a one with k featured training example using U matrix. 
The concept involves projection of data points on a plane when the data is converted from 3 features to 2 features and from a plane to a line when the data is converted from 2 features to a single feature example.

Data projection and recovery algorithms are also implemented.