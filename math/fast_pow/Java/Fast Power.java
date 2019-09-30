// Calculate the a^n % b where a, b and n are all 32-bit integers.

class Solution {
    public int fastPower(int a, int b, int n) {
        if (n == 0) {
            return 1 % b;
        }
        
        if (n == 1) {
            return a % b;
        }
        
        long result = fastPower(a, b, n / 2);
        
        if (n % 2 == 0) {
            return (int)(result * result % b);
        } else {
            return (int)(result * result % b * (a % b) % b); // first mod is to avoid overflow
        }
    }
};