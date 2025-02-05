class Solution {
public:
    void solve(vector<vector<char>>& board) {
       int m = board.size(), n = board[0].size();
        if (m == 0 || n == 0) return;
        
        // Lambda function to perform BFS
        auto bfs = [&](int r, int c) {
            queue<pair<int, int>> q;
            q.push({r, c});
            board[r][c] = '#'; // Mark as visited
            
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                
                for (auto [dx, dy] : directions) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O') {
                        board[nx][ny] = '#';
                        q.push({nx, ny});
                    }
                }
            }
        };
        
        // Start BFS from the boundary 'O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') bfs(i, 0);
            if (board[i][n - 1] == 'O') bfs(i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') bfs(0, j);
            if (board[m - 1][j] == 'O') bfs(m - 1, j);
        }
        
        // Replace remaining 'O' with 'X' and '#' back to 'O'
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};
