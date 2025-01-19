/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return buildTree(grid, 0, 0, grid.size());
    }

private:
    Node* buildTree(const vector<vector<int>>& grid, int row, int col, int size) {
        if (isUniform(grid, row, col, size)) {
            // Create a leaf node with the uniform value
            return new Node(grid[row][col] == 1, true);
        }

        // Divide the grid into four quadrants
        int newSize = size / 2;
        Node* topLeft = buildTree(grid, row, col, newSize);
        Node* topRight = buildTree(grid, row, col + newSize, newSize);
        Node* bottomLeft = buildTree(grid, row + newSize, col, newSize);
        Node* bottomRight = buildTree(grid, row + newSize, col + newSize, newSize);

        // Create an internal node
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    bool isUniform(const vector<vector<int>>& grid, int row, int col, int size) {
        int val = grid[row][col];
        for (int i = row; i < row + size; ++i) {
            for (int j = col; j < col + size; ++j) {
                if (grid[i][j] != val) {
                    return false;
                }
            }
        }
        return true;
    }
};