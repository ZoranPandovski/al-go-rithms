function sieveOfEratosthenes(n) {
    var prime = [];

    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true.
    for (var i = 0; i <= n; i++)
        prime[i] = true;

    for (var p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) {
            // Update all multiples of p greater than or  
            // equal to the square of it 
            // numbers which are multiple of p and are 
            // less than p^2 are already been marked.  
            for (var i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Return list of all prime numbers
    var prime_list = [];
    for (var p = 2; p <= n; p++)
        if (prime[p])
            prime_list.push(p);

    return prime_list
}

module.exports = sieveOfEratosthenes;