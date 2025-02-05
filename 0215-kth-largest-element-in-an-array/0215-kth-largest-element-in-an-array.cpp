class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
  sort(arr.rbegin(),arr.rend());
  return arr[k-1];
    }
};