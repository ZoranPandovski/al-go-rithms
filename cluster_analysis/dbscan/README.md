# DBSCAN Clustering
Density-based spatial clustering of applications with noise (DBSCAN) is a data
clustering algorithm proposed by Martin Ester, Hans-Peter Kriegel, Jörg Sander
and Xiaowei Xu in 1996. It is a density-based clustering algorithm: given a
set of points in some space, it groups together points that are closely packed
together (points with many nearby neighbors), marking as outliers points that
lie alone in low-density regions (whose nearest neighbors are too far away).
DBSCAN is one of the most common clustering algorithms and also most cited in
scientific literature.

## Algorithm
The DBSCAN algorithm can be abstracted into the following steps:

- Find the ε (eps) neighbors of every point, and identify the core points with
  more than minPts neighbors.
- Find the connected components of core points on the neighbor graph, ignoring
  all non-core points.
- Assign each non-core point to a nearby clusters at at most distance ε (eps),
  otherwise assign it to noise.
- A naive implementation of this requires storing the neighborhoods in step 1,
  thus requiring substantial memory. The original DBSCAN algorithm does not
  require this by performing these steps for one point at a time.

## Results
![](https://upload.wikimedia.org/wikipedia/commons/0/05/DBSCAN-density-data.svg)

