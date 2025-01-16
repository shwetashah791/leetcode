class Solution {
public:
    int mySqrt(int x) {
       if (x < 2) return x;  // Return x directly for 0 and 1

        int left = 2, right = x / 2;  // The range for the square root is from 2 to x / 2
        while (left <= right) {
            int mid = left + (right - left) / 2;  // Correct way to calculate mid
            long long midSquared = (long long)mid * mid;  // Square of mid to prevent overflow

            if (midSquared == x) {
                return mid;  // Found the exact square root
            } else if (midSquared < x) {
                left = mid + 1;  // Search the right half
            } else {
                right = mid - 1;  // Search the left half
            }
        }

        return right;  // If not found exactly, right will be the largest integer whose square is <= x
    }
};