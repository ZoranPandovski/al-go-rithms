function centroids = kMeansInitCentroids(X, K)
%KMEANSINITCENTROIDS This function initializes K centroids that are to be 
%used in K-Means on the dataset X
%   centroids = KMEANSINITCENTROIDS(X, K) returns K initial centroids to be
%   used with the K-Means on the dataset X
%

% You should return this values correctly
centroids = zeros(K, size(X, 2));

%set centroids to randomly chosen examples from
%               the dataset X
%
randomIndex = randperm(size(X,1));
centroids = X(randomIndex(1:K),:);







% =============================================================

end

