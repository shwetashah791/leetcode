class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        auto kadane=[&](int sign){
            int curr=0,result=sign*nums[0];
            for(int num:nums){
                curr=max(sign* num,curr+sign*num);
                result=max(result,curr);
            }
            return sign*result;
        };
        int maxLinearSum=kadane(1);
        int minLinearSum=kadane(-1);
        if(maxLinearSum<0){
            return maxLinearSum;
        }
        return max(maxLinearSum,totalSum-minLinearSum);
    }
};