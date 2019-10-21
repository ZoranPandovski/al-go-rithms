## Normal Distribution (Gaussian Distribution)

Normal distribution, also known as the Gaussian distribution, is a probability distribution that is symmetric about the mean, showing that data near the mean are more frequent in occurrence than data far from the mean. In graph form, normal distribution will appear as a bell curve.

Most of the real world data is obtained such that it can be fit on a curve that is commonly known as the Normal Equation or Normal Distribution Curve.

The files here consist of preparing a Multivariate - Gaussian Distribution that can be used to detect anomalies in given data. 

* estimateGaussian.m is used to determine parameters mean and standard deviation for each feature.
* multivariateGaussian.m implements the Gaussian Kernel for multivariate data (many features).
* The selectThreshold.m can be used to select an appropriate threshold (epsilon) below which if the pval (Anomalies have lower pval) is obtained, the data can be classified as an anomaly.

