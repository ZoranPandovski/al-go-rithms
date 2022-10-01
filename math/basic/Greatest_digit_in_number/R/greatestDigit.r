{
    x = as.integer(readline(prompt = "Enter a number :"))
    
    g = 0
    while (x > 0) {
      y = x %% 10
      if (g < y) {
        g = y
      }
      x = x %/% 10
    }
    print(paste("Greatest digit: ", g))
}