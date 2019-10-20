creatingBuckets <- function(arr) {
  o <- list(c(), c(), c(), c(), c(), c(), c(), c(), c(), c())
  for (i in 1:length(arr)) {
    n <- as.integer(floor(10 * arr[i]))
    o[[n]] <- c(o[[n]], arr[i])
  }
  for (i in 1:length(o)) {
    if(length(o[[i]])>1){
      o[[i]] <- insertionSort(o[[i]])
    }
  }
  mergeList(o)
}
insertionSort <- function(a) {
  for (c in 2:(length(a))) {
    d = c
    while (d > 1 && (a[d] < a[d-1])) {
      t = a[d]
      a[d] = a[d - 1]
      a[d - 1] = t
      d = d - 1
    }
  }
  a
}
mergeList <- function(q) {
  res <- as.vector(c())
  for (k in 1:length(q)) {
    if (!is.null(q[[k]]))
      res <- c(res, q[[k]])
  }
  print("Vector after BucketSort")
  print(res)
}
arr <- c(0.78, 0.17, 0.39, 0.26)
creatingBuckets(arr)
