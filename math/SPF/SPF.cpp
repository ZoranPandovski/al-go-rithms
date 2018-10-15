#include <bits/stdc++.h>
using namespace std;

void leastPrimeFactor(int n)
{
    // Create a vector to store least primes.
    // Initialize all entries as 0.
    vector<int> least_prime(n + 1, 0);

    // We need to print 1 for 1.
    least_prime[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        // least_prime[i] == 0
        // means it i is prime
        if (least_prime[i] == 0)
        {
            // marking the prime number
            // as its own lpf
            least_prime[i] = i;

            // mark it as a divisor for all its
            // multiples if not already marked
            for (int j = 2 * i; j <= n; j += i)
                if (least_prime[j] == 0)
                    least_prime[j] = i;
        }
    }

    // print least prime factor of
    // of numbers till n
    for (int i = 1; i <= n; i++)
        cout << "Least Prime factor of "
             << i << ": " << least_prime[i] << "\n";
}

// Driver program to test above function
int main()
{
    int n = 10;
    leastPrimeFactor(n);
    return 0;
}