# Principal Components Analysis (PCA)

import numpy as np


def pca(X, n_components=2):
    """
    Computes PCA and returns the principal components.
    :param X: The data, N x D numpy array
    :param n_components: Number of principal components, int
    :return: The compressed data, N x n_components numpy array
    """

    # Get the data dimensions
    N, D = X.shape

    # Center the data
    mu = np.mean(X, axis=0)
    X -= mu

    # Calculate the covariance matrix
    C = 1/N * (X.T @ X)

    # Eigen decomposition yields principal directions
    _, V = np.linalg.eigh(C)

    # Sort the eigenvectors in descending order according to their eigenvalues
    V = V[:, ::-1]

    # Compression
    Y = X @ V[:, :n_components]

    # (optional) Reconstruction
    # Z = Y @ V[:, :n_components].T + mu
    return Y


# Execute PCA with a sample dataset

if __name__ == "__main__":
    import matplotlib.pyplot as plt
    from sklearn import datasets

    # Get the iris data
    iris = datasets.load_iris()
    X = iris.data
    y = iris.target

    # PCA with 2 principal components
    Z = pca(X)
    plt.figure(1, figsize=(8, 6))
    plt.scatter(Z[:, 0], Z[:, 1], c=y)
    plt.title('PCA')
    plt.xlabel('PC 1')
    plt.ylabel('PC 2')
    plt.show()
