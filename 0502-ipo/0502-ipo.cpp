class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       int n = profits.size();
        vector<pair<int, int>> projects;
        
        // Step 1: Store projects as (capital, profit) pairs and sort by capital
        for (int i = 0; i < n; ++i) {
            projects.emplace_back(capital[i], profits[i]);
        }
        sort(projects.begin(), projects.end()); // Sort by required capital

        priority_queue<int> maxProfitHeap; // Max heap to store available project profits
        int i = 0;

        // Step 2: Select up to k projects
        while (k--) {
            // Add all projects that can be started with current capital
            while (i < n && projects[i].first <= w) {
                maxProfitHeap.push(projects[i].second);
                i++;
            }

            // If there are no projects that can be started, stop
            if (maxProfitHeap.empty()) break;

            // Step 3: Pick the most profitable project
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return w;
    }
};
