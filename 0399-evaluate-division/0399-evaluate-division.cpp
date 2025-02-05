class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;
    
    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0], B = equations[i][1];
            double value = values[i];
            graph[A].push_back({B, value});
            graph[B].push_back({A, 1.0 / value});
        }
    }
    
    double dfs(string src, string dst, unordered_map<string, bool>& visited) {
        if (graph.find(src) == graph.end() || graph.find(dst) == graph.end()) return -1.0;
        if (src == dst) return 1.0;
        
        visited[src] = true;
        for (auto& neighbor : graph[src]) {
            string next = neighbor.first;
            double weight = neighbor.second;
            if (!visited[next]) {
                double result = dfs(next, dst, visited);
                if (result != -1.0) {
                    return weight * result;
                }
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        graph.clear();
        buildGraph(equations, values);
        
        vector<double> results;
        for (auto& query : queries) {
            string C = query[0], D = query[1];
            unordered_map<string, bool> visited;
            results.push_back(dfs(C, D, visited));
        }
        return results;
    }
};
