class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int> combination;
        backtrack(1,n,k,combination,result);
        return result;
    }
    private:
    void backtrack(int start,int n,int k,vector<int>& combination,vector<vector<int>>& result){
        if (combination.size() == k) {
            // If the combination size is k, add it to the result
            result.push_back(combination);
            return;
        }

        for (int i = start; i <= n; ++i) {
            combination.push_back(i); // Choose the current number
            backtrack(i + 1, n, k, combination, result); // Recur for the next numbers
            combination.pop_back(); // Unchoose the current number
        }
    }
};