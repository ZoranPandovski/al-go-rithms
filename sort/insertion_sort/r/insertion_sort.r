insertion_sort <- function(a) {
  for (c in 2:(length(a))) {
    d = c
    while (d > 1 && a[d] < a[d - 1]) {
      t = a[d]
      a[d] = a[d - 1]
      a[d - 1] = t
      d = d - 1
    }
  }
  a
}
startTime <- Sys.time()
insertion_sort(c(8, 71, 6, 25, 4, 3, 2, 12, 1))
endTime <- Sys.time()
timeTaken <- endTime - startTime
cat("Time required : ", as.numeric(timeTaken), "\n")
