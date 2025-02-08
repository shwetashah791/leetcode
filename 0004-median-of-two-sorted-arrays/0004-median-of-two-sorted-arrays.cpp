class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        // Make sure m is the smaller size
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left = 0;
        int right = m;
        
        while (left <= right) {
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            
            int maxLeftX = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRightX = (i == m) ? INT_MAX : nums1[i];
            
            int maxLeftY = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRightY = (j == n) ? INT_MAX : nums2[j];
            
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                } else {
                    return (double)max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
        
        return 0;
    }
};

