mergeSort <- function(x) {
  len <- length(x)
  if (len < 2)
    result <- x
  else {
    y <- x[1:(len / 2)]
    z <- x[-(1:(len / 2))]
    cat("Call mergeSort with parameter", y, "\n")
    y <- mergeSort(y)
    cat("Call mergeSort with parameter", z, "\n")
    z <- mergeSort(z)
    result <- c()
    cat("Merge ", y, " and ", z)
    while (min(length(y), length(z)) > 0) {
      if (y[1] < z[1]) {
        result <- c(result, y[1])
        y <- y[-1]
      } else{
        result <- c(result, z[1])
        z <- z[-1]
      }
    }
    if (length(y) > 0)
      result <- c(result, y)
    else
      result <- c(result, z)
  }
  return (result)
}



startTime <- Sys.time()
r <- mergeSort(c(38, 27, 43, 39, 82))
print(r)
endTime <- Sys.time()
timeTaken <- endTime - startTime
cat("Time required : ", as.numeric(timeTaken), "\n")
