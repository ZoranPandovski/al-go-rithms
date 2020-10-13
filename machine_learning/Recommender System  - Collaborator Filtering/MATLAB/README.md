## Recommender System - Collaborative Filtering

Collaborative Filtering is a naive Recommender System based on the the given training data set X, which includes the users as columns and rated object by the users in rows. The fact that the user rated an object in another two dimensional matrix R.

Two matrices are minimized simultaneously which are, the feature matrix of the objects and preference matrix of the users, thereby the name is called Collaborative Filtering.

* The input and output dataset is first normalized using columnwise mean of the dataset in normalizeRatings.m.
* The feature and preferences matrix is initialised using random values.
* The matrices are unrolled into the Cost Function to calculate cost and gradient which is minimized further using linear regression [regularized] to train the matrices.
* Minimization can be done using a modified function fmincg.
* The matrices are returned unrolled which can be used with the test examples to find the expected rating for the object given by the user.
