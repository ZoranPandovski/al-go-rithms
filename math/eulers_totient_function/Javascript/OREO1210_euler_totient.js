
// Javascript program to calculate Euler's Totient Function
 
// Function to return gcd of a and b
function gcd(a, b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
 
// A simple method to evaluate Euler Totient Function
function phi(n)
{
    let result = 1;
    for (let i = 2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}
 
// Driver Code 
for (let n = 1; n <= 10; n++)
    document.write(`phi(${n}) = ${phi(n)} <br>`);
 