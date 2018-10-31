sieve <- function(n)
{
   n <- as.integer(n)
   if(n > 1e6) stop("n too large")  # restricting for larger values of n
   primes <- rep(TRUE, n) # initially all false
   primes[1] <- FALSE # trivial case
   last.prime <- 2L
   for(i in last.prime:floor(sqrt(n)))  # looping through the array
   {
      primes[seq.int(2L*last.prime, n, last.prime)] <- FALSE
      last.prime <- last.prime + min(which(primes[(last.prime+1):n]))
   }
   which(primes)
}

 sieve(1000000) # calling the function
