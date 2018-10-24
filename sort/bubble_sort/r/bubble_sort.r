bubble_sort <- function(a){
  for(i in 1:(length(a)-1)){
    for (j in 1:(length(a)-1)) {
      if(a[j] > a[j+1]){
        t = a[j]
        a[j] = a[j+1]
        a[j+1] = t
      }
    }
  }
  print(a)
}
startTime <- Sys.time()
bubble_sort(c(-2,45,0,11,-9))
endTime <- Sys.time()
timeTaken <- endTime - startTime
cat("Time required : ", as.numeric(timeTaken), "\n")
