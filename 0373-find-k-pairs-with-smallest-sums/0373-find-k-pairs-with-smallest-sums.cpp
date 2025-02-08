class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        for (int i = 0; i < nums1.size(); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        
        vector<vector<int>> result;
        
        while (k-- > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            result.push_back({nums1[top.second.first], nums2[top.second.second]});
            
            if (top.second.second + 1 < nums2.size()) {
                pq.push({nums1[top.second.first] + nums2[top.second.second + 1], {top.second.first, top.second.second + 1}});
            }
        }
        
        return result;
    }
};
