{
    n = as.integer(readline(prompt = "Enter a number :"))
    
    s = 9
    while (x > 0) {
      y = x %% 10
      if (s > y) {
        s = y
      }
      x = x %/% 10
    }
    print(paste("Smallest digit:", s))
}