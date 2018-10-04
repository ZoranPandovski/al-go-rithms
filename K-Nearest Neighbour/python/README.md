## K-Nearest Neighbors
K-Nearest neighbor is machine learning algorithm that can used for classification and regression.
In both cases, the input consists of the k closest training examples in the feature space. The output depends on whether k-NN is used for classification or regression:
 * In k-NN classification, the output is a class membership. An object is classified by a majority vote of its neighbors, with the object being assigned to the class most common among its k nearest neighbors (k is a positive integer, typically small). If k = 1, then the object is simply assigned to the class of that single nearest neighbor.
 * In k-NN regression, the output is the property value for the object. This value is the average of the values of its k nearest neighbors.

![Image of KNN](https://cdn-images-1.medium.com/max/960/0*Sk18h9op6uK9EpT8.)
Example of k-NN classification. The test sample (green circle) should be classified either to the first class of blue squares or to the second class of red triangles. If k = 3 (solid line circle) it is assigned to the second class because there are 2 triangles and only 1 square inside the inner circle. If k = 5 (dashed line circle) it is assigned to the first class (3 squares vs. 2 triangles inside the outer circle).

Further reference: https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm
