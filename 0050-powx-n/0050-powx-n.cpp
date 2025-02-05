class Solution {
public:
    double myPow(double x, int n) {
       if (n == 0) return 1.0; // Base case: anything to the power 0 is 1
        
        long long exp = n; // Use long long to handle edge case when n = INT_MIN
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 == 1) { // If exponent is odd
                result *= x;
            }
            x *= x; // Square the base
            exp /= 2; // Halve the exponent
        }

        return result;
    }
};