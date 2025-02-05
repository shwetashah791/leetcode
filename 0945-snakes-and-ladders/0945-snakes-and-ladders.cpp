class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
         int n = board.size();
        vector<int> moves(n * n + 1, -1);
        bool leftToRight = true;
        int index = 1;
        
        // Flatten the board into a 1D array
        for (int i = n - 1; i >= 0; i--) {
            if (!leftToRight) {
                reverse(board[i].begin(), board[i].end());
            }
            for (int j = 0; j < n; j++) {
                moves[index++] = board[i][j];
            }
            leftToRight = !leftToRight;
        }
        
        queue<pair<int, int>> q;
        q.push({1, 0}); // {position, moves}
        vector<bool> visited(n * n + 1, false);
        visited[1] = true;
        
        while (!q.empty()) {
            auto [pos, steps] = q.front();
            q.pop();
            
            if (pos == n * n) return steps;
            
            for (int i = 1; i <= 6; i++) {
                int nextPos = pos + i;
                if (nextPos > n * n) break;
                
                if (moves[nextPos] != -1) {
                    nextPos = moves[nextPos];
                }
                
                if (!visited[nextPos]) {
                    visited[nextPos] = true;
                    q.push({nextPos, steps + 1});
                }
            }
        }
        
        return -1; // Not reachable
    }
};
