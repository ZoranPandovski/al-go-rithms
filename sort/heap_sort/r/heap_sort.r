sort <- function() {
  for (i in floor(n / 2):1) {
    heapify(n, i)
  }
  for (i in n:1) {
    t <- p[1]
    p[1] <<- p[i]
    p[i] <<- t
    heapify(i, 1)
  }
}
heapify <- function(n, i) {
  largest = i
  l = 2 * i
  r = 2 * i + 1
  if ((l < n) && (p[l] > p[largest])) {
    largest <- l
  }
  if ((r < n) && (p[r] > p[largest])) {
    largest <- r
  }
  if (largest != i) {
    t <- p[i]
    p[i] <<- p[largest]
    p[largest] <<- t
    heapify(n, largest)
  }
}

startTime <- Sys.time()
p <- c(4, 10, 3, 5, 1)
n <- length(p)
sort()
print("Sorted array is ")
print(p)
endTime <- Sys.time()
timeTaken <- endTime - startTime
cat("Time required : ", as.numeric(timeTaken), "\n")
